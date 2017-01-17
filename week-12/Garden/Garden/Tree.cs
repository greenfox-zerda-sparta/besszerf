namespace Garden
{
    class Tree : Plants
    {
        public Tree(string Color)
        {
            Type = "Tree";
            WaterAmount = 0;
            this.Color = Color;
            absorb = 0.4;
            minimumWaterLevel = 10;
        }
    }
}
