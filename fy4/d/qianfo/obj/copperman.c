// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name( "»ëÉí²¼Âú¾­ÂçÍ¼µÄÍ­ÈË", ({ "copperman","man"  }) );
	set("unit", "¸ö");
	set("no_get",1);
	set("value",20);
	set("long","
ÕâÊÇÒ»¸ö»ëÉí²¼Âú¾­ÂçÍ¼µÄÍ­ÈË£¬ÔÚÍ­ÈËµÄ[31mĞÄ£¨£è£å£á£ò£ô£©[32m£¬
[1;32m¸Î£¨£ì£é£ö£å£ò£©[0;32m£¬[33mÎ¸£¨£ó£ô£ï£í£á£ã£è£©[32m£¬[37m·Î£¨£ì£õ£î£ç£©[32m£¬
[34mÉö£¨£ë£é£ä£î£å£ù£©[32mµÄ²¿Î»¸÷ÓĞÒ»Ğ¡¿×£¬ÔÚÍ­ÈËµÄµ¤ÌïÖ®´¦»¹ÓĞ
¸öºÜÉîµÄÕÆÓ¡£¨£í£á£ò£ë£©£®
\n");
	set_weight(5000);
	::init_item();
}
void init()
{
	add_action("do_touch","touch");
}

int closepath()
{
        object env;
        env = environment(this_object());
        if( !env->query("exits/north") ) return 1;
        message("vision","Í­ÈËÓÖ¶¯ÁËÆğÀ´£¬×ª»Øµ½Ô­À´µÄÎ»×Ó£®£®£®\n",env );
		env->delete("exits/north");
}
int open_path()
{
        object env;
        env = environment(this_object());
        if( !env->query("exits/north"))
        {
	        env->set("exits/north",AREA_QIANFO"tianwang");
		message("vision","Í­ÈËÑÛ¾¦ºöÈ»Õö¿ª£¬¶¯ÁËÆğÀ´£¬Â¶³öÁËÉíºóµÄ°µµÀ£¡£¡\n",env);
	        call_out("closepath",5);
        }
        return 1;
}

int check_needles()
{
	object liver,kidney,stomach, heart, lung, env,*inv;
	object red,green,yellow, white,black;
	env = environment(this_object());
	if(!objectp(liver=present("liver",env))) return 0;
	if(!objectp(kidney=present("kidney",env))) return 0;
	if(!objectp(stomach=present("stomach",env))) return 0;
	if(!objectp(heart=present("heart",env))) return 0;
	if(!objectp(lung=present("lung",env))) return 0;
	
	inv = all_inventory(liver);
		if( sizeof(inv) != 1) return 0;
		green = inv[0];
		if((string)green->query("name") != "ÂÌÉ«µÄÏ¸Õë" && green->query("name") != "µ­ÂÌÉ«µÄÏ¸Õë" ) return 0;
        
    inv = all_inventory(kidney);
        if( sizeof(inv) != 1) return 0;
        black = inv[0];
        if((string)black->query("name") != "ºÚÉ«µÄÏ¸Õë" && black->query("name") != "µ­ºÚÉ«µÄÏ¸Õë") return 0;
    
    inv = all_inventory(stomach);
        if( sizeof(inv) != 1) return 0;
        yellow= inv[0];
        if((string)yellow->query("name") != "»ÆÉ«µÄÏ¸Õë" && yellow->query("name") != "µ­»ÆÉ«µÄÏ¸Õë") return 0;
    
    inv = all_inventory(heart);
        if( sizeof(inv) != 1) return 0;
        red= inv[0];
        if((string)red->query("name") != "ºìÉ«µÄÏ¸Õë" && red->query("name") != "µ­ºìÉ«µÄÏ¸Õë") return 0;
    
    inv = all_inventory(lung);
        if( sizeof(inv) != 1) return 0;
        white= inv[0];
        if((string)white->query("name") != "°×É«µÄÏ¸Õë" && white->query("name") != "µ­°×É«µÄÏ¸Õë") return 0;
// now we have everything, let's open path! and reset this room;
		red->move(env); destruct(red);
        green->move(env); destruct(green);
        yellow->move(env); destruct(yellow);
        white->move(env); destruct(white);
        black->move(env); destruct(black);
	open_path();
	return 1;
}

int do_touch(string arg)
{
        object me,env;
        if( !arg ) return 0;
        if( arg != "ÕÆÓ¡" && arg != "mark") return 0;
        me = this_player();
        if((int) me->query("force") < 50) {
        	write("ÄãµÄÄÚÁ¦²»¹»£¨Ğè50µãÄÚÁ¦£©£¡\n"); 
            return 1;
        }
        me->add("force",-50);
        
        message_vision("$N½«Ò»¹ÉÄÚÁ¦ËÍÈëÍ­ÈËÌåÄÚ£®£®£®\n",me);
        // if there is needles 
        if(!check_needles() ) {
	        REWARD_D->riddle_done(me,"ÎåĞĞÍ­ÈË",10,1);		
			if(!me->query_temp("marks/copperman"))
				me->set_temp("marks/copperman",1);
			open_path();
			return 1;
		}
		
        // No needles
                
        
	// for non-xingguo players, each login only need insert needles once.
		if( me->query_temp("marks/copperman")) {
            open_path();
            return 1;
        }
        
        // for xingguo students, it needs 200 force w/o needles
        if( me->query("class")=="bonze") {
            env = environment(this_object());
            message("vision","Í­ÈËÑÛ¾¦ºöÈ»Õö¿ª£¬¶¯ÁËÆğÀ´£¬Â¶³öÁËÉíºóµÄ°µµÀ£¡£¡\n",env);
			message_vision("$NÒ»×İÉí½øÁË°µµÀ£¬Í­ÈËÔÚ$NÉíºóÓÖºÏÉÏÁË¡£\n",me);
			me->move("/d/qianfo/tianwang");
            return 1;
        }

        message_vision("ÔÚ$NÆøÁ¦ÒÑ½ßµÄË²¼ä£¬Í­ÈËÑÛ¾¦ËÆºõ½«ÒªÕö¿ª£¡£¡\n",me);
        return 1;
}
