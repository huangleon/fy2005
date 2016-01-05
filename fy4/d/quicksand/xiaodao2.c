inherit ROOM;

void create()
{
	set("short", "·Ï¾ÉæäµÀ");
	set("long", @LONG
ÕâÊÇÌõ¶«Î÷×ßÏòµÄ·Ï¾ÉæäµÀ£¬µÀÉÏĞĞÈËÁÈÁÈ£¬Ê±½üÉîÇï£¬·ÅÑÛÍûÈ¥£¬¾¡ÊÇ¿İÊ÷
°Ü²İ£¬Ë··çËàÉ±£¬´µµÃÒ°²İÆğ·ü²»¶¨£¬·çÉ³Ò²²»Ê±´µ½øÂÃÈËµÄË«ÑÛ£¬Ò²¿´²»ÇåÇ°·½
¾¿¾¹ÈçºÎ¡£Ïò±±µÄÂ·ÅÆÉÏĞ´×Å£º[33m¡º¸»¹óÉ½×¯¡»[32m
LONG);
	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"north":AREA_FUGUI"yidao1",
		"east":__DIR__"xiaodao1",
		"west":__DIR__"xiaodao3",
	]) );

	set("coor/x",-800);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
