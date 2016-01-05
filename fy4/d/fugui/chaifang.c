inherit ROOM;

void create()
{
	set("short", "²ñ·¿");

	set("long", @LONG
¸»¹óÉ½×¯µÄ²ñ·¿ºÃÏñ²¢²»ÊÇ¶Ñ²ñµÄ£¬¶øÊÇ¹ØÈËµÄ¡£¼ÒÈË×¥×¡ÁËÇ¿µÁ£¬¶¼»á½«Ëû
¹ØÔÚ²ñ·¿Àï¡£²ñ·¿ÀïÓÐÖ©Öë£¬ÓÐÀÏÊó£¬ÓÐ¹·ÊºÃ¨Äò£¬ÀÃ¹øÆÆÍë£¬ÓÐÓÃÊ£ÏÂµÄ[33mÃºÐ¼[32m¡£
¼¸ºõÊ²÷á¶¼ÓÐ£¬¾ÍÊÇÃ»ÓÐ²ñÁ¬¸ù²ñ¶¼Ã»ÓÐ¡£ 
LONG
	);

	set("type","house");
	set("indoors", "fugui");
	set("exits",([
		"south":__DIR__"grass4",
	]) );
	set("objects" , ([
		__DIR__"npc/suan":1,
	]));
    	set("item_desc", ([
        	"ÃºÐ¼": "²ñ·¿Àïµ½´¦¶¼ÊÇÃºÐ¼£¬ÄãËÆºõ¿ÉÒÔ´òÉ¨Ò»ÏÂ£¨clean£©¡£\n",
        	"breeze": "²ñ·¿Àïµ½´¦¶¼ÊÇÃºÐ¼£¬ÄãËÆºõ¿ÉÒÔ´òÉ¨Ò»ÏÂ£¨clean£©¡£\n",
        ]) );

	set("coor/x",10);
	set("coor/y",250);
	set("coor/z",80);
	setup();
	
}

void init()
{
        add_action ("do_dight", "clean");
}

int do_dight()
{		
	object mh,bo;
	int eff_kee;
        if (!present("saoba",this_player())) 
        	return notify_fail("ÄãÉíÉÏÃ»ÓÐÉ¨°Ñ£¬ÔõÃ´´òÉ¨£¿\n");
        eff_kee = this_player()->query("kee");
        if (eff_kee < (int)this_player()->query("max_kee")/10)
        {
        	return notify_fail("ÄãÌ«ÀÛÁË£¬ÔõÃ´´òÉ¨£¿\n");
        }
	this_player()->receive_damage("kee",(int)this_player()->query("max_kee")/10);
	if (this_object()->query("dighted"))
	{	message_vision("$NÄÃ×ÅÉ¨°Ñ¶þ»°²»Ëµ´òÉ¨ÆðÀ´£¬\n¶ÙÊ±²ñ·¿ÀïÑïÆðÂþÌìµÄ»Ò³¾£¬¼òÖ±ÇºµÃÍ¸²»¹ýÆø£¬\nÐÁ¿àÁËÒ»·¬£¬ÎÝ×Ó×ÜËã¸É¾»ÁËÐ©¡£\n\n", this_player() );
        	return 1;
        }
	else if (random(5)) 
	{
		message_vision("$NÄÃ×ÅÉ¨°Ñ¶þ»°²»Ëµ´òÉ¨ÆðÀ´£¬\n¶ÙÊ±²ñ·¿ÀïÑïÆðÂþÌìµÄ»Ò³¾£¬¼òÖ±ÇºµÃÍ¸²»¹ýÆø£¬\nÐÁ¿àÁËÒ»·¬£¬ÎÝ×Ó×ÜËã¸É¾»ÁËÐ©¡£\n\n", this_player());
        	return 1;
	}
	else 
	{
		message_vision("$NÄÃ×ÅÉ¨°ÑÐÁÐÁ¿à¿àµØÉ¨×Å£¬Í»È»ÔÚÒ»¸öºÚ°µµÄ½ÇÂäÀï£¬ËÆºõ·¢ÏÖÓÐÒ»¸öÐ¡Ä¾ºÐ×Ó¡£\n", this_player());
		this_object()->set("dighted",1);
		mh=new(__DIR__"obj/muhe");
		bo=new(BOOKS"spear_50");
		bo->move(mh);
		mh->move(this_player());
		return 1;
	}
	return 0;
}

void reset(){
        ::reset();
      
	if(this_object()->query("dighted")){
                this_object()->delete("dighted");
        }
        return;
}         