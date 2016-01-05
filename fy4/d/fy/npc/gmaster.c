// teacher.c
//Modified by justdoit 04/11/2001

inherit NPC;
#include <ansi.h>

int test_dart();
void create_level(object me, object who,string name, int exp);

void create()
{
        set_name("²éÃÍ", ({ "zha meng", "meng" }) );
    	set("long","
½ğÊ¨ÕÆ²éÃÍÊÇÉÙÁÖË×¼ÒµÜ×Ó£¬ÈË²»µ«ĞÔÇéºÀË¬£¬ÇÒ¹ã½»ÅóÓÑ£®
·²ÊÇÏëÏòËûÇó½ÌµÄ£¬Ö»ÒªÎªïÚ¾Ö[37m³öÁ¦[32m£¬Ëû¾Í¿Ï½Ì¡£
£¨£á£ó£ë¡¡£í£å£î£ç¡¡£á£â£ï£õ£ô¡¡£÷£ï£ò£ë£©\n"
        );
    	set("nickname", HIY "½ğÊ¨ÕÆ"NOR);
    	set("gender", "ÄĞĞÔ" );
    	set("age", 32);
    	create_family("ÉÙÁÖ", 21, "Ë×¼ÒµÜ×Ó");
    	set("skill_public",1);
    	set("reward_npc", 1);
    	set("difficulty", 4);
    	set("attitude", "peaceful");
    	
       	set("inquiry",	([
        	"mission" : 	(: test_dart :),
        	"»¤ïÚ" : 	(: test_dart :),
		 "¹¦·ò": 	"»õ²ÖÀïÕıÈ±ÈËÊÖ£¬ÄãÈ¥°ïĞ©Ã¦°É£¬ÍêÊÂÁËÎÒ½ÌÄãÁ½ÊÖ¡£
£¨£ì£å£á£ò£î¡¡£ø£ø£ø¡¡£æ£ò£ï£í¡¡£ú£è£á¡¡£í£å£î£ç¡¡£÷£é£ô£è¡¡£±£©\n",
		 "³öÁ¦": 	"»õ²ÖÀïÕıÈ±ÈËÊÖ£¬ÄãÈ¥°ïĞ©Ã¦°É£¬ÍêÊÂÁËÎÒ½ÌÄãÁ½ÊÖ¡£
£¨£ì£å£á£ò£î¡¡£ø£ø£ø¡¡£æ£ò£ï£í¡¡£ú£è£á¡¡£í£å£î£ç¡¡£÷£é£ô£è¡¡£±£©\n",
		 "work": 	"»õ²ÖÀïÕıÈ±ÈËÊÖ£¬ÄãÈ¥°ïĞ©Ã¦°É£¬ÍêÊÂÁËÎÒ½ÌÄãÁ½ÊÖ¡£
£¨£ì£å£á£ò£î¡¡£ø£ø£ø¡¡£æ£ò£ï£í¡¡£ú£è£á¡¡£í£å£î£ç¡¡£÷£é£ô£è¡¡£±£©\n",
		 "job": 	"»õ²ÖÀïÕıÈ±ÈËÊÖ£¬ÄãÈ¥°ïĞ©Ã¦°É£¬ÍêÊÂÁËÎÒ½ÌÄãÁ½ÊÖ¡£
£¨£ì£å£á£ò£î¡¡£ø£ø£ø¡¡£æ£ò£ï£í¡¡£ú£è£á¡¡£í£å£î£ç¡¡£÷£é£ô£è¡¡£±£©\n",
		 "chufeng":	"Ñ§ÁËÎÒµÄÂŞººÈ­£¬¾ÍÄÜÓÃÕâÕĞ³û·ïÕ¹³á£¨£ğ£å£ò£æ£ï£ò£í¡¡£ã£è£õ£æ£å£î£ç£©",
		 "³û·ïÕ¹³á":	"Ñ§ÁËÎÒµÄÂŞººÈ­£¬¾ÍÄÜÓÃÕâÕĞ³û·ïÕ¹³á£¨£ğ£å£ò£æ£ï£ò£í¡¡£ã£è£õ£æ£å£î£ç£©",
		 "ÂŞººÈ­":	"Ñ§ÁËÎÒµÄÂŞººÈ­£¬¾ÍÄÜÓÃÕâÕĞ³û·ïÕ¹³á£¨£ğ£å£ò£æ£ï£ò£í¡¡£ã£è£õ£æ£å£î£ç£©",
		 "ÓÆÓÎÎŞ³¾²½":   "action²éÃÍÒ¡Ò¡Í·Ëµ£¬ÓÆÓÎÎŞ³¾²½ËäÈ»²»Ë×£¬È´Ã»Ê²Ã´ÌØÊâÕĞÊ½¡£\n",
		 "wuchen-steps":   "action²éÃÍÒ¡Ò¡Í·Ëµ£¬ÓÆÓÎÎŞ³¾²½ËäÈ»²»Ë×£¬È´Ã»Ê²Ã´ÌØÊâÕĞÊ½¡£\n",
	]) );
    	
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"²éÃÍËµµÀ£ºÕâ¸öÔÂïÚ¾ÖÉúÒâ²»´í£¡\n",
            	"²éÃÍËµµÀ£º»¤ïÚ£¨£í£é£ó£ó£é£ï£î£©µÄÊÂ£®£®£®£®\n",
            	"²éÃÍËµµÀ£ºÕâÒ»ÕĞ¡°³û·ïÕ¹³á¡±£¨chufeng£©ÄËÊÇÂŞººÈ­µÄ¾«Ëè£¡\n",
            	"²éÃÍËµµÀ£ºĞ¡×Ó£¬¿´Äã½î¹Ç²»´í£¬ÏëÑ§¹¦·òÃ´£¿\n",
            }) );
    	  
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
          (: perform_action, "unarmed.chufeng" :)
        }) );
    	
    	set_skill("unarmed", 100);
    	set_skill("literate", 100);
    	set_skill("force", 100);
    	set_skill("dodge",100);
    	set_skill("move", 100);
    	set_skill("parry",100);
    	set_skill("wuchen-steps",200);
    	set_skill("luohan-quan",200);
    	set_skill("foreknowledge",100);
    	set_skill("chanting",100);
    	set_skill("perception",100);
    	map_skill("unarmed", "luohan-quan");
    	map_skill("dodge","wuchen-steps");
    
    	set("combat_exp", 3500000);
    	setup();
    	carry_object(__DIR__"obj/jinzhuang")->wear();
}

int recognize_apprentice(object ob)
{
    	if((time() - ob->query("marks/½ğÊ¨") ) > 1800  ){
        	say("²éÃÍËµµÀ£ºÄã£®£®ÄãºÃÏóºÜ¾ÃÃ»ÎªïÚ¾Ö³ö¹ıÁ¦ÁË....\n");
        	return 0;
    	}
	return 1;
}

int test_dart()
{
    	object me;
	
    	me=this_player();
    	if (query("marks/gived")+600> time() )
    	{
        	command("say ÎÒÃÇïÚ¾ÖÏÖÔÚÃ»ÓĞÄãÒª»¤µÄïÚ¡£");
        	return 1;
    	}
    	command("say ÏÖÔÚÄÏ¹¬Ç®×¯ÓĞÒ»±ÊïÚÒøĞèÒªÔËµ½³ÁÏãÕò£¬Äã¿ÉÔ¸ÒâĞ­ÖúÎÒÃÇ£¿(accept mission)");
    	add_action("do_accept", "accept");
    	return 1;
}

int do_accept(string arg)
{    
    	object ob,cart,biaotou;
    	object me,*team;
    	int i, exp;	
    
    	if (arg != "mission") return 0;
    
    	me=this_player();
    	team=me->query_team();
    	if (sizeof(team)==0) team=({me});

   		if (sizeof(team) != 0 && (team[0]!=me)) 
        	return notify_fail("Ö»ÓĞ¶ÓÎéÊ×Áì²ÅÄÜÌá³ö½ÓïÚ¡£\n");
	
    	for (i=0;i<sizeof(team);i++)
    	{
        	if (!intp(team[i]->query("deposit")) 
        		|| team[i]->query("deposit")<200000)
        	{
            		command("say »¤ïÚÊÇÎ£ÏÕµÄÊÂ£¬ÎÒ¿´"+RANK_D->query_respect(team[i])+"Ã»ÓĞÅâ³¥ÄÜÁ¦¡£");
            		return 1;
        	}
    		if (team[i]->query("combat_exp")>exp)
    		exp= team[i]->query("combat_exp");
    	} 

		if (exp < 1000000){
            command("say »¤ïÚÂ·Í¾Î£ÏÕ£¬ÎÒ¿´ÕâÎ»Ğ¡ÅóÓÑËÆºõ²»ÒË£¡£¨¶ÓÎéÖĞ×î¸ß¾­ÑéĞèÒª28¼¶ÒÔÉÏ£©");
            return 1;
        }
			
//begin: modified by justdoit
	if (query("marks/gived")+ 600 > time())	{
		 command("say ÄãÀ´ÍíÁË£¬ÒÑ¾­ÓĞÈË½ÓÏÂÕâÖ§ïÚÁË¡£");
		 return 1;
	}
//end: modified by justdoit

    	set("marks/gived",time());
    	command("say ºÃ°É¡£¸ú×ÅÀîïÚÍ·×ß°É¡£");
    	command("say ¶ªïÚ¿ÉÊÇÒªÅâË«·İµÄ£¬Ò»Â·Ğ¡ĞÄ¡£");
    
    	me->set("marks/½ÓïÚ",time());	
    	say("Ò»¶ÓïÚ³µ´ÓÄÚÔºÊ»³ö¡£\n");
	
    	ob=new(__DIR__"obj/cart");
    	ob->move(environment());
    	cart=ob;
	
    	biaotou=new(__DIR__"biaotou");
    	biaotou->move(environment());
    	biaotou->get_quest("/d/fy/cartway1");
    	biaotou->set_cart(cart);
    	biaotou->set_protector(team);
    	biaotou->set("combat_exp",exp);
    	create_level(me,biaotou,"biaotou",exp);
	
    	ob=new("/d/fy/obj/biaoyin");
    	ob->set_amount(10+random(10));
    	ob->move(cart);
	
    	ob=new(__DIR__"biaoshia");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);	
    	create_level(me, ob,"biao",3*exp/4);
 
    	ob=new(__DIR__"biaoshi1a");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);
    	create_level(me, ob,"biao",3*exp/4);		
	
    	ob=new(__DIR__"biaoshi1a");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);
    	create_level(me, ob,"biao",3*exp/4);	
    
    	for(i=0;i<sizeof(team);i++)
       		team[i]->set_temp("protecting",cart);
    	
    	me->set_temp("protecting",cart);
    	me->set_leader(biaotou);
    	biaotou->go_now();
    	return 1;	
}

void reset()
{
    	delete("marks/gived");
}



void create_level(object me, object who,string name, int exp)
{
 	int level;
 	level=100+130*(exp-1000000)/5500000;
 	if (exp<1000000) level=100;
 	if (exp>6400000) level=230;
 	level=level*level/100;
 	if (name=="biaotou") {
	 	who->set("toughness",200);
	 	"/feature/nada"->reset_npc(who);
		who->set("agi",who->query("agi")*3/4);
    	who->set("str",who->query("str")/2);
    	who->full_me();		
		who->set_skill("hammer", 70 + random(level/2));
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("changquan",50+random(level/2));
		who->set_skill("unarmed",70 + random(level/2));
		return;
	} 	
 	if (name=="biao") {
	 	"/feature/nada"->reset_npc(who);
		who->set("agi",who->query("agi"));
    	who->set("str",who->query("str"));
    	who->full_me();		
		who->set_skill("hammer", 70 + random(level/2));
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("changquan",50+random(level/2));
		who->set_skill("unarmed",70 + random(level/2));
		return;
	}
	if (name=="gangster" || name == "gangsterboss") {
		who->set("toughness",70);
    	"/feature/nada"->reset_npc(who);
    	who->set("agi",who->query("agi")*3/4);
    	who->set("str",who->query("str")*3/4);
    	who->full_me();		
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("blade",70+random(level/2));
		who->set_skill("demon-steps",70+random(level/2));
		who->set_skill("unarmed",70+ random(level/2));
		who->set_skill("demon-strike",50+random(level/8));
		who->set_skill("demon-blade",50+random(level/8));
		return;
	}

}