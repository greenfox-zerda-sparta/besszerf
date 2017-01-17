using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Garden
{
    class Plants
    {
        public string Type { get; set; }
        public string Color { get; set; }
        public double WaterAmount { get; set; }
        public virtual void Watering(double amount) { }
        public virtual bool NeedsWater() { return false; }
    }

    class Flower : Plants
    {
        public Flower(string Color)
        {
            this.Type ="Flower";
            this.WaterAmount = 0;
            this.Color = Color;
        }

        public override void Watering(double amount)
        {
            WaterAmount += 0.75 * amount;
        }

        public override bool NeedsWater()
        {
            if (WaterAmount < 5) {
                return true;
            }
            return false;
        }
    }

    class Tree : Plants
    {
        public Tree(string Color)
        {
            this.Type = "Tree";
            this.WaterAmount = 0;
            this.Color = Color;
        }

        public override void Watering(double amount)
        {
            WaterAmount += 0.4 * amount;
        }

        public override bool NeedsWater()
        {
            if (WaterAmount < 10)
            {
                return true;
            }
            return false;
        }
    }

}
