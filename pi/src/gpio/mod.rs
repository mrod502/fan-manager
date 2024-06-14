pub mod pwm;

pub type WriteResult<T> = Result<T, Box<dyn std::error::Error>>;
pub type Value = u8;
pub enum Pin {
    GPIO0,
    GPIO1,
    GPIO2,
    GPIO3,
}

pub fn write_gpio(_pin: Pin, _value: Value) -> WriteResult<()> {
    Ok(())
}
