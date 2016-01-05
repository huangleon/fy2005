inherit ROOM;
void create()
{
    set("short", "Òø¹³¶Ä·»Æ«Ìü");
    set("long", @LONG
ËÄÃæµÄÇ½±Ú·ÛË¢µÄÏóÑ©¶´Ò»Ñù£¬ÉÏÃæ¹ÒÂúÁË¹Å½ñÃû¼ÒµÄ[33m×Ö»­[32m¡£×î´óµÄÒ»·ùÉ½Ë®£¬
ÅÅÔÚÕıÖĞ£¬È´ÊÇ¸öÎŞÃûĞ¡×ä»­µÄ£¬°ÑÔÆÎíÆàÃÔµÄÔ¶É½£¬»­µÃ¾ÍÏó´ò·­ÁËÄ«Ë®¸×Ò»Ñù¡£
ºÍÄÇĞ©Ãû¼ÒµÄ½Ü×÷Ò»±È£¬ÊµÔÚÊÇ²»¿°ÈëÄ¿£¬ÁîÈË²»¸Ò¹§Î¬¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"dating",
      ]));
    set("item_desc", ([
	"picture": "Õâ·ù×Ö»­ËÆºõ¿ÉÒÔÏÆ¿ª(open)¡£\n",
	"×Ö»­": "Õâ·ù×Ö»­ËÆºõ¿ÉÒÔÏÆ¿ª(open)¡£\n",
	"É½Ë®": "Õâ·ù×Ö»­ËÆºõ¿ÉÒÔÏÆ¿ª(open)¡£\n",
	"hua": "Õâ·ù×Ö»­ËÆºõ¿ÉÒÔÏÆ¿ª(open)¡£\n",

      ]) );

    set("objects", ([
	__DIR__"npc/leng" : 1,
	__DIR__"npc/fangyufei" : 1,
      ]) );

    set("coor/x",-180);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

void init()
{
    add_action("do_open", "open");
}
int do_open(string arg)
{
    object obj;
    object me;
    if(!arg || arg=="")
    {
	write("ÄãÒª´ò¿ªÊ²Ã´£¿\n");
	return 1;
    }
    if( arg == "picture" || arg == "×Ö»­" || arg == "hua")
    {
	me = this_player();
	message_vision("$NÀ­ÆğÇ½ÉÏµÄ×Ö»­£¬·¢ÏÖÁËÒ»¸ö°µÃÅ¡£\n", me);
	if( !query("exits/westdown") ) {
	    set("exits/westdown", __DIR__"zhoulang");
	    call_out("close_path", 1);
	}
	return 1;
    }
    else
    {
	write("Äã²»¿ÉÒÔ´ò¿ª"+arg+"\n");
	return 1;
    }
}
void close_path()
{
    if( !query("exits/westdown") ) return;
    message("vision",
      "É½Ë®»­µ´ÁË»ØÀ´£¬ÓÖÕÚ×¡ÁË°µÃÅ¡£\n",
      this_object() );
    delete("exits/westdown");
}

