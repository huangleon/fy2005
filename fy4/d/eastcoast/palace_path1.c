inherit ROOM;

void create()
{
        set("short", "³à·åÂ·");
        set("long", @LONG
ÔÙÍù¶«ÊÇÉ½Çø£¬Õâ¶ùÊÇ²íÂ·¿Ú£¬ÏòÄÏµÄÂ·¿íÀ«·±»ª£¬Ö±Í¨µÀ½ÌÊ¥µØ[33mÎäµ±É½[32m¡£¶«
·½µÄÅ¨ÎíÖ®ÖÐËÊÁ¢×ÅÒ»×ù°µºìÉ«µÄÆæ·å£¬Ö±²åÔÆÏö£¬ÔÆÖÐÓÐ¼¸Í·²ÔÓ¥ÔÚµÍµÍµÄÅÌÐý
åÛÏè£¬·Â·ðÔÚÑ°ÕÒÁÔÎï¡£¶«±±ÏòµÄ[33mºÚËÉÉ½[32mÉÏÔÆÎíçÔÈÆ£¬É½½ÅÏÂÓÐ¼¸»§ÈË¼Ò¡££¨µÚ
Ò»´Î½øÏàË¼ÁëÐè×ÓÊ±»òÎçÊ±¡££© 
LONG
        );
        set("exits", ([ 
  	"east" : 	__DIR__"palace_path2",
  	"west" : 	AREA_FYCYCLE"fyeast",
  	"northeast" :   AREA_CHUENYU"dustyroad0",
  	"south" :       AREA_WUDANG"bwuroad1",
]));
        set("outdoors", "palace");

	set("coor/x",100);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_go","go");
}


int do_go(string dir){
	
	object me;
	object *inv, ob;
	mixed *local;
	int i,flag=0;
	

	me = this_player();
	local = NATURE_D->getTime(time());

	if (userp(me) && me->query("class") == "moon"	&& dir == "east")
	{
		ob = find_object("/d/xiangsi/qishi");
		if (!ob)
			ob=load_object("/d/xiangsi/qishi");
		message_vision("É½ÉÏÍ»È»Æ®ÏÂÒ»²ãÅ¨Îí£¬ö®Ê±¼ä½üÔÚåë³ßµÄ¾°É«Òà±»ÕÚ×¡¡£\n",me);
		me->move(ob);
		tell_object(me,"Äã±ÕÉÏÑÛ¾¦£¬°´×ÅÊìÏ¤µÄ¼ÇÒä×ªÈë£¬Ì¤½øÏàË¼ÁëÖÐ¡£\n");
		message("vision","Å¨Îí×ªÑÛ¼äÏûÉ¢ÎÞ×Ù£¬Äã¾õµÃÉí±ßËÆºõÍ»È»ÉÙÁËÒ»¸öÈËÓ°£®£®£®\n",this_object()); 
		return 1;
	}

	if( userp(me))
	{
		if (dir == "west" && me->query_temp("annie/xiangsi_enterance") == 0)
			me->set_temp("annie/xiangsi_enterance",1);
		else if (dir == "east" && me->query_temp("annie/xiangsi_enterance") == 6)
		{
			if (local[1] == 0 || local[1] == 6 || me->query_temp("marks/xiangsi/entrance")
				|| REWARD_D->check_m_success(me,"°ÍÉ½Ö®ÃØ"))
			{
				ob = find_object("/d/xiangsi/qishi");
				if (!ob)
					ob=load_object("/d/xiangsi/qishi");
				message_vision("É½ÉÏÍ»È»Æ®ÏÂÒ»²ãÅ¨Îí£¬ö®Ê±¼ä½üÔÚåë³ßµÄ¾°É«Òà±»ÕÚ×¡¡£\n",me);
				me->move(ob);
				tell_object(me,"ÄãÔÚ´óÎíÀïÏòÉ½ÉÏÐÐµÃÆ¬¿Ì£¬ºöÈ»¾ª¾õ¸½½üµÄ¾°É«¾¹Óë¼ÇÒäÖÐ´ó²»ÏàÍ¬¡£\n");
				if (!REWARD_D->check_m_success(me,"°ÍÉ½Ö®ÃØ")) {
					REWARD_D->riddle_done( me, "°ÍÉ½Ö®ÃØ",10,1);		
					tell_object(me,"\b£¨Äã¼Ç×¡ÁËÕâÀïµÄµØÐÎ£¬ÒÔºóÎÞÐèÔÙµÈ´ý×ÓÎçË«Ê±ÁË¡££©\n");
				}
				me->set_temp("marks/xiangsi/entrance",1);
				me->delete_temp("annie/xiangsi_enterance");
				message("vision","Å¨Îí×ªÑÛ¼äÏûÉ¢ÎÞ×Ù£¬Äã¾õµÃÉí±ßËÆºõÍ»È»ÉÙÁËÒ»¸öÈËÓ°£®£®£®\n",this_object()); 
				return 1;
			}
			else
				me->delete_temp("annie/xiangsi_enterance");
		}
		else
			me->delete_temp("annie/xiangsi_enterance");
	}
	
	return 0;
}
