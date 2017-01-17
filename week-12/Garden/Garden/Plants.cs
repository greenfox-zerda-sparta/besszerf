
namespace Garden
{
    class Plants
    {
        public string Type { get; set; }
        public string Color { get; set; }
        protected double WaterAmount { get; set; }
        protected double absorb;
        protected int minimumWaterLevel;

        public void Watering(double amount)
        {
            WaterAmount += absorb * amount;
        }

        public bool NeedsWater()
        {
            return (WaterAmount < minimumWaterLevel);
        }
    }
}
