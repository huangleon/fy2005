inherit __DIR__"no_killing_place";
void create()
{
    set("short", "ÕıÌü");
    set("long", @LONG
Ò»¼ä²¢²»¿í³¨µÄÊé·¿£¬È´ÊÕÊ°µÃÇåË¬¿ÉÈË¡£ÓÒ±ßÖñÁ±´°éºÖ®ÏÂ£¬°Ú×ÅÒ»ÕÅ×ÏÌ´
°¸¼¸£¬ÉÏÃæ³ÂÉè×ÅÒ»ÕÅ½¹Ä¾¹ÅÇÙ£¬ÇÙÉíÎÚºÚ¹âÁÁ£¬Ã»ÓĞ°ëµã»Ò³¾¡£ÇÙÅÔÓÖÓĞÒ»ÖñÖÆ
»¨Í²£¬È´²å×ÅÒ»Ö¦É½¼ä³£¼ûµÄÂÌÒ¶¡£×ó±ßÒ²ÊÇÒ»ÕÅ×ÏÌ´Êé×À£¬ÉÏÃæĞ±Ğ±µÄÌ¯¿ª¼¸±¾
Ïß×°Êé£¬Ò»±­Çå²è£¬ÓÌ×ÔÓàÎÂ¡£ÎİµÄÕıÖĞ£¬¸ßĞü×ÅÒ»¸±¿ñ²İÖĞÌÃ£º

¡¡¡¡¡¡¡¡¡¡¡¡[1;37mÊÀÈË¶¼ËµÉñÏÉºÃ£¬ÎÒÖ»ÏÛÔ§²»ÏÛÏÉ[2;37;0m

LONG
        );
    set("exits", ([ 
        "south" : __DIR__"cyard",
        "east" : __DIR__"grassland",
	]) );

    set("item_desc", ([
	"¿ñ²İÖĞÌÃ": "Ò»¸±Ä«±Ê¿ñ²İÊé·¨£¬ĞĞÔÆÁ÷Ë®£¬ÆøÊÆ°õíç£¬¸üÓĞÒ»ÖÖËµ²»³öµÄĞş»úÔĞº¬ÔÚ×ÖÀïĞĞ¼ä£®£®\n",
	"writing": "Ò»¸±Ä«±Ê¿ñ²İÊé·¨£¬ĞĞÔÆÁ÷Ë®£¬ÆøÊÆ°õíç£¬¸üÓĞÒ»ÖÖËµ²»³öµÄĞş»úÔĞº¬ÔÚ×ÖÀïĞĞ¼ä£®£®\n",
	]) );
    set("no_magic", 1);
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
    setup();
}

void init()
{
	::init();
    add_action("do_search", "search");
}

int do_search(string arg)
{
    object me, obj;
    
    me = this_player();
    
    if(!arg || arg != "room" && arg != "Êé·¿") return 0; 
    if(me->query_temp("marks/marble") && !query("marks/gone"))
    {
        message_vision("$NÔÚÊé·¿ÄÚ·­Ïäµ¹¹ñµØÕÒÁËÒ»·­¡£\n", me);		
        tell_object(me, "ÖÕÓÚÄãÔÚ½¹Ä¾¹ÅÇÙµÄÏÂÃæÕÒµ½ÁËÒ»¸öĞ¡Ë®¾§Çò¡£\n");
        message("vision",me->name()+
                "ÍµÍµÃşÃşµØ´Ó½¹Ä¾¹ÅÇÙÏÂÄÃ³öÁË¸ö¶«Î÷·Åµ½»³Àï¡£\n",
                environment(me), me);
        me->delete_temp("marks/marble");
        set("marks/gone",1);
        obj = new(__DIR__"obj/marble");
        obj->move(me);
        return 1;
    }
    message_vision("$NÔÚÊé·¿ÄÚ·­Ïäµ¹¹ñµØÕÒÁËÒ»·­¡£\n", me);		
    tell_object(me, "ÄãÈ´Ã»·¢ÏÖÊ²Ã´ÓĞ¼ÛÖµµÄ¶«Î÷¡£\n");
    return 1;	
}

void reset()
{
    ::reset();
    delete("marks/gone");
}
