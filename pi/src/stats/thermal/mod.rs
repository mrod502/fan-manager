use std::{fs::File, io::Read};

pub type Error = Box<dyn std::error::Error>;
pub type ReadResult<T> = Result<T, Error>;
pub enum ZoneInterface {
    ThermalZone0Temp,
}

pub struct Temp(usize);

impl Into<f64> for Temp {
    fn into(self) -> f64 {
        self.0 as f64 / 1000.0
    }
}
impl Into<f32> for Temp {
    fn into(self) -> f32 {
        self.0 as f32 / 1000.0
    }
}

fn read_zone_interface(interface: ZoneInterface) -> ReadResult<String> {
    let path = match interface {
        ZoneInterface::ThermalZone0Temp => "/sys/class/thermal/thermal_zone0/temp",
    };
    let mut file = File::open(path)?;

    let mut temp = String::new();
    file.read_to_string(&mut temp)?;
    Ok(temp)
}

pub fn read_zone_temp(interface: ZoneInterface) -> ReadResult<Temp> {
    let temp_str = read_zone_interface(interface)?;
    let parsed = temp_str.trim().parse::<usize>();

    match parsed {
        Ok(temp) => Ok(Temp(temp)),
        Err(e) => Err(Box::new(e)),
    }
}
