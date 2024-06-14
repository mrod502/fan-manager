use std::{error::Error, fs};

pub fn list_devices() -> Result<Vec<String>, Box<dyn Error>> {
    println!("Listing PWM devices");
    let paths = fs::read_dir("/sys/class/pwm")?;
    let mut result = vec![];
    for path in paths {
        match path {
            Ok(entry) => {
                let path = entry.path();
                let path = path.to_str().unwrap().to_string();
                result.push(path);
            }
            Err(_) => {}
        }
    }
    Ok(vec![])
}
