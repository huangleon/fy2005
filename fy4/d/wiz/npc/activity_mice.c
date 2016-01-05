#define RESET_TIMES 8
#include <ansi.h>
inherit NPC;
int last_reset_time=RESET_TIMES;
//int time_period(int timep, object me);
//int wait_period(int timep, object me);

void create()
{
	set_name(HIM"÷úÊó"NOR, ({ "job mouse" }) );
    	set("race", "Ò°ÊŞ");
        set("age", 1);
        set("title", HIY"µÃÁ¦ÖúÊÖ"NOR);
        set("nickname",WHT"´Ï»ÛÁéÎï"NOR);
        set("per",100);
        set("long","
Ò»Ö»Æ¯ÁÁ´ÏÃ÷µÄ´óÀÏÊó£¬¸ºÔğ´òÀíWIZÈÕ³£¹¤×÷£¬»î¶¯ÆÚ¼ä×ÜÊÇÌØ±ğ·±Ã¦¡£\n");
        set("combat_exp",200000);
        set("NO_KILL","÷úÊóÕâÃ´ÈÇÈËÏ²°®µÄÑù×ÓÄãÔõÃ´ÈÌĞÄÏÂÊÖ¡£\n");      
        set_skill("dodge", 200);        
        set_temp("armor", 200);

    	setup();
}

void reset(){
	if (environment() && last_reset_time>=RESET_TIMES) {
		string *area = ({ 	
			"huangshan", "huashan", "songshan", "palace", "laowu", 
			"resort", "qianfo", "qingping", "taoguan","fy","chenxiang",
			"xinjiang","wanmei","eren","fugui","guanwai","jinan",
			"wudang","taiping",
			"chuenyu", "taishan", "guanyin","wolfmount","qianjin",
			"biancheng", "zangbei","baiyun" ,"bat","changchun"});
			
		string *c_area =  ({"»ÆÉ½","»ªÉ½","áÔÉ½","µÛÍõ¹È","±ù·âĞ¡Õò",
					"ÌúÑ©É½×¯","Ç§·ğÉ½","ÇåÆ½É½×¯","ÈıÇåÉ½","·çÔÆ³Ç","³ÁÏãÕò",
					"ĞÂ½®", "ÍòÃ·É½×¯","¶ñÈË¹È","¸»¹óÉ½×¯","¹ØÍâ","¼ÃÄÏ",
					"Îäµ±É½","Ì«Æ½Õò",
				    "ºÚËÉÉ½","Ì©É½","Ìì·ãÉ½×¯","ÀÇÉ½","Ç§½ğÂ¥", 
				    "±ß³Ç", "²Ø±±","°×ÔÆµº","òùòğµº","³¤´ºµº",
				    });
	
		string arg, arg1, room_name, *files;
		int num,i,m,size;
		object room;
		object sm;
		object me = this_player();
		
		num=18+random(9)+random(9);
	
		for (int n=0;n<num;n++) {
			
			m = random(sizeof(area));
			arg1 = "/d/"+area[m] +"/";
			arg = arg1+"*.c";
			files= get_dir(arg);
	
			
	
			while(1)
			{
				i = random(sizeof(files));
				size = sizeof(files[i]);
				//message_vision("file is "+ files[i] +"\n", me);
				//if(files[i][(size-2)..size]==".c")
				//{
					room_name = arg1 + files[i];
					room = find_object(room_name);
					if (!room)
						room = load_object(room_name);
					if (!room)	continue;
					if (!room->query("short")) 		continue;
					if (room->query("no_fly")) 		continue;
					if (room->query("no_fight")) 	continue;	
					if (room->query("underwater")) 	continue;
					break;
				//}
			}
			sm = new("/obj/treasure/npc/monsternian");
			sm->move(room);
			//message_vision("monsternian move to /d/"+ area[m] +"/"+ files[i]+"\n", me);
			//command("chat [1;31msnowman move to /d/"+ area[m] +"/"+ files[i]+"[0;32m");
		}
		last_reset_time=0;
		command("chat [1;37mÑÛÈôÍ­Áå£¬À´È¥Èç·çµÄ[1;33mÄêÊŞ[1;37m³öÏÖÔÚ[1;39m·çÔÆ´åÄÚ¡£[0;32m");
	} else {
		last_reset_time++;
	}
	log_file("HIPPO_DEBUG", sprintf("Ë¢ĞÂÊ±¼äºÍÊıÖµ¼ÇÂ¼£º%s,%d\n",ctime(time()),last_reset_time));
}