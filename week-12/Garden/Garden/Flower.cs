namespace Garden
{
    class Flower : Plants
    {
        public Flower(string Color)
        {
            Type = "Flower";
            WaterAmount = 0;
            this.Color = Color;
            absorb = 0.75;
            minimumWaterLevel = 5;
        }
    }
}
