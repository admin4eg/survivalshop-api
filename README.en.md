# SurvivalShop API

A sample plugin which adds new "permissions" item.

The plugin is using CPP REST SDK v2.9.1

## Sample json config:

// once pushased this item, user will be added to permissions group "Premium"
{
	"type": "permissions",
	"do": "add",
	"group": "Premium"
}

// once pushased this item, user will be removed from permissions group "RestrictBuilding"
{
	"type": "permissions",
	"do": "remove",
	"group": "RestrictBuilding"
}

## More info:

http://www.survivalshop.org
http://survivalhost.wiki/index.php?title=Ark:Донат-Магазин/API