inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();

void create()
	{
	    set_name( "���ʦ̫" , ({ "master qing", "master" }) );
	    set("nickname",WHT "�ľ���ˮ" NOR);
	    set("gender", "Ů��");
	    set("age", 46);
	    set("long","
���ƹ�����Ȼ�޵���ȴ��������ͽ����硢����ʦ̫��������ǰ��Ѿͷ�����ʦ̫
ԭ�Ǳ������������幬��ǰ�Ĺ¶������ƹ������������㽫�������������Ҳ����
����У��������������ѧ��¯���࣬�ѹ��ڵ�����Ҳ���ŵ�ͷͷ�ǵ���������
�������������������ʦ̫��������۵��ڵ��ң��������Ƕ����Ƶ��²����ˡ�
\n");
	
	    set("combat_exp", 3000000);
	    set("score", 20000);
	    set("reward_npc", 1);
	    set("difficulty", 10);
	    set("class", "taoist");
		
	    set("no_dodge_snow",1);
	    set("atman", 1400);
	    set("max_atman", 1400);
	    set("mana", 4000);
	    set("max_mana", 4000);
	    
	    set("inquiry", ([
	        "�����ķ�":  "�����ķ��������幬Ϊ�Կ�аħ����������ڹ��ķ���\n",
	        "���幬":   "�����幬������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n",
	         "leave" : (: leave :),
		]) );
	
	    set("apprentice_available", 3);
	    set("chat_chance_combat", 80);
	    set("chat_msg_combat", ({
	        	(: cast_spell, "drainerbolt" :),
	    }) );
	
	    create_family("���幬", 6, "����");
	    set("rank_nogen",1);
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"����","��ͯ","����","С�ɹ�","�ɹ�","ɢ��","����ɢ��",
			"����ɢ��","̫��ɢ��","����","��������","��������",YEL"̫������"NOR,
			YEL"��Ů"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));

	    set("guard_msg",HIW"$N�ȵ������幬����Ů�ӣ�ȴҲ�����������裡\n"NOR);
	
	    set_skill("literate", 100);
	    set_skill("perception", 150);
	    set_skill("chanting",150);
	    
	    set_skill("foreknowledge", 100);
	    set_skill("force", 150);
	    set_skill("spells", 150);
	    set_skill("move", 150);
	    set_skill("unarmed", 150);
	    set_skill("sword", 150);
	    set_skill("tenderzhi", 150);
	    set_skill("parry", 150);
	    set_skill("dodge", 150);
	    set_skill("gouyee", 150);
	    set_skill("notracesnow", 150);
	    set_skill("snowshade-sword", 150);
	    set_skill("taoism", 150);
	    set_skill("scratmancy",150);
	    set_skill("scratching",150);
	    set_skill("necromancy",150);
	    
	    map_skill("spells", "necromancy");
	    map_skill("unarmed", "tenderzhi");
	    map_skill("parry", "snowshade-sword");
	    map_skill("sword", "snowshade-sword");
	    map_skill("move", "notracesnow");
	    map_skill("dodge", "notracesnow");
	    map_skill("force","gouyee");
	    map_skill("scratching","scratmancy");
	    			
	    set_temp("apply/dodge", 200);
	    set_temp("apply/armor", 200);
	
	    setup();
	    carry_object(__DIR__"obj/r_sword")->wield();
	    carry_object(__DIR__"obj/tcloth")->wear();
	    
}

void attempt_apprentice(object ob)
{
    	if( query("apprentice_available") ) {
        	if( find_call_out("do_recruit") != -1 )
            		command("say ������һ��һ������");
        	else
            		call_out("do_recruit", 2, ob);
    	} else {
        	command("say ƶ�������Ѿ������������ӣ���������ͽ�ˡ�");
    	}
}

void do_recruit(object ob)
{
    
    	if( (string)ob->query("gender") != "Ů��" )
		{
        	command("say ƶ���ǳ����ˣ���������ͽ��ʩ��������ذɡ�");
			return;
		}
    	
    	else if(ob->query("marry") && !ob->query("jiebai")) {
			message_vision("$Nҡ��ҡͷ˵������λ�������м��ң���λ����������У�\n",this_object(), ob);
			return;
     	}	  
    	             
        command("say ��... ���������幬��Ҳ��....");
        command("recruit " + ob->query("id") );
        
}

int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "taoist");
    	
    	add("apprentice_availavble", -1);
}


void init()
{	
	object me = this_player();
	::init();
	 if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
	add_action("do_killing", "kill");
}

void greeting(object me)
{
        object ob,*inv, ding;
        
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
                        
        if (me->query("class")=="taoist" )        {
                
                inv = all_inventory(me);
                if  ( sizeof(inv) >= 15) 
                        return;
        
                if (present("ding",me)) return;
                
                message_vision(CYN"$N��$n˵���������Ϊʦ���꣬���մ���һ�����������ܹ��ʦ�š���\n"NOR,ob,me);
                ding= new("/obj/specials/ding/ding_baby");
                if (me->query("combat_exp")>5000000) {
                        ding->set("name",RED"��ľ����"NOR);
                        ding->set_max_encumbrance(300);
                } else if (me->query("combat_exp")>3000000) {
                   ding->set("name",YEL"��ľ����"NOR);
                        ding->set_max_encumbrance(200);
                } else {
                        ding->set("name",HIC"��ľ����"NOR);
                        ding->set_max_encumbrance(100);
                }
                ding->move(me);
                message_vision("$N�ӻ���ȡ��һ��"+ding->name()+"�ݸ�$n��\n",ob,me);     
                return;
        }
                
} 

int leave() {
	if (this_player()->query("class")!="taoist") return 0;
	message_vision(CYN"$N���������������Ų��⴫���������˿ɲ�Ҫ��ڡ�\n"NOR, this_object(),this_player());
	return 1;
}
