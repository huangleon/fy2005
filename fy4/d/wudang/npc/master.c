inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave();

void create()
{
    	set_name("ʯ��", ({ "master shi", "master", "shi" }) );
    	set("nickname", "��������");
    	set("gender", "����");
    	set("age", 62);
    	set("long","
ʯ���˵����䵱���ţ�����̫���ķ������Ž����������˼��ߵľ��硣
�����侫̫ͨ�����У����������ǵ�����˫�������˳ơ��������ˡ���\n");
    
    	set("combat_exp", 50000000);
    	set("score", random (20000));

    	set("class", "wudang");
    	
    	create_family("�䵱��", 57, "������");
    	set("rank_nogen",1);
    	set("ranks",({"��ʿ","С����","����","С��ʦ","��ʦ",YEL"����ʦ"NOR,YEL"������"NOR,
                      HIY"����"NOR}));
    	
    	set("fly_target",1);	

    	set("atman", 20000);
    	set("max_atman", 20000);
		set("mana", 20000);
		set("max_mana", 20000);
		set("max_force", 20000);
		set("force", 20000);
    		
    	set("inquiry", ([
        	"̫���ķ�": "̫���ķ��˵������ŵĻ����ķ����ܹ��������ڵ�����������\n",
        	"�䵱��":   "���䵱���������˿�ɽ����������������������������Ϊ���Ρ�\n",
 	 	"leave" : (: leave :),
         ]) );

    
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
    	    	(: cast_spell, "jixing" :),
            	(: perform_action, "sword.nianzijue" :),
             }) );


    	set_skill("unarmed", 160);
    	set_skill("force", 170);
    	set_skill("foreknowledge", 160);
    	set_skill("parry",160);
    	
        set_skill("literate", 100);
    	set_skill("move", 150);
    	set_skill("sword", 200);
    	set_skill("dodge", 150);
    	set_skill("changelaw", 150);
    	set_skill("taiji-sword", 150);
    	set_skill("taijiforce", 150);
    	set_skill("taiji", 150);
    	set_skill("five-steps", 150);
    	set_skill("spells",100);
    	set_skill("qixing",100);
    	set_skill("incarnation",160);
    	set_skill("perception", 100);
    
    
    	map_skill("spells","qixing");
    	map_skill("parry", "taiji-sword");
    	map_skill("sword", "taiji-sword");
    	map_skill("move", "five-steps");
    	map_skill("dodge", "five-steps");
    	map_skill("literate", "changelaw");
    	map_skill("force", "taijiforce");
    	map_skill("unarmed", "taiji");

    	setup();

    	carry_object(__DIR__"obj/msword")->wield();
    	carry_object(__DIR__"obj/mcloth")->wear();
    	carry_object(__DIR__"obj/mhat")->wear();
}


void attempt_apprentice(object ob)
{
    	command("say �ϵ�Ҫ�չ��������꣬�䵱���Ҳ�����ͽ��\n");
    	return;
    	
    	if(ob->query("marry")){
		message_vision("$N����һ�����䵱���£�û���϶���Ů�ġ���\n", 
				this_object(), ob);
		return;
    	} 	   
    	if( (string)ob->query("marks/�䵱��ͽ") )
        	command("say " + ob->query("name") + "���㻹�����������ң�");
    	else {
        	command("recruit " + ob->query("id") );
    	}
}

int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "wudang");
    	add("apprentice_availavble", -1);
}


int accept_object(object who, object ob)
{
    	object book;

    	if((string)ob->name() != "���Ʒɵ��غ�") return 0;
    	
    	command("say ��л��λ" + RANK_D->query_respect(who));
    	command("say �Ȿ������������ɡ�");
    	book = new(BOOKS"skill/wudang_11");
    	if (!book->move(who))
    		destruct(book);
    	return 1;
}


void die()
{
    	object ob;
    	if( !ob = query_temp("last_damage_from") )
        	ob = this_player(1);
    	if(ob) 
        	ob->set_temp("killed_master_shi",1);
    	::die();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_killing", "kill");
}

void greeting(object ob)
{
        object *inv,letter, *sy_inv, things;
        int i,j;
        int got_sword = 0;
        if( !ob || environment(ob) != environment() ) return;
        
        if (ob->query_temp("marks/newbie_quest")==1)    {
                message_vision(CYN"$N���˸���˵����ʯ�������ˣ��������������ʺã���\n"NOR,ob);
                message_vision(CYN"
ʯ��Ǻ�һЦ˵����̩ɽһ����أ������ô����ȥ���Ƴ�������ˣ�
Ҳ���ϵ������ʺã���\n"NOR,this_object());
                tell_object(ob,WHT"\n�������������˵�������Ľ��������ḻ�ˣ�\n"NOR);
                tell_object(ob,WHT"��ʹ��hp������Բ鿴�����ڵľ���ȼ�״����\n"NOR);
                ob->add("combat_exp",500);
                ob->delete_temp("marks/newbie_quest");
                REWARD_D->riddle_set(ob,"��������",2);
                return;
        }

        if(ob->short() == "�䵱������(wudang master)") {
        

                if(REWARD_D->riddle_check(ob,"�䵱����") == 5 
                	|| REWARD_D->check_m_success(ob,"�䵱����"))
				{
                for(i=0; i<sizeof(inv); i++)
                if(inv[i]->query("name")=="���") destruct(inv[i]);
                command("say ���ģ��⣬�⣬���ǣ��ǣ��ϣ�������ô��\n");
                message_vision("$NͻȻһ����Ѫ���˳��������ŵ�������ϣ���ɫ���ڣ�һͷ�Ե��ڵ��¡�\n",
                this_object());
                ob->set_temp("killed_master_shi",1);
                
                sy_inv = all_inventory(this_object());
                for(j=0;j<sizeof(sy_inv);j++){
                        things = sy_inv[j];
                        destruct(things);
                }
	
                sy_inv = all_inventory(ob);

                for(j=0;j<sizeof(sy_inv);j++)
				{
                        things = sy_inv[j];
						if (things->query("fakegender"))
	                        destruct(things);
                }
	
				if (!REWARD_D->check_m_success(ob,"�䵱����"))
					REWARD_D->riddle_set(ob,"�䵱����",6);

                message_vision(CYN"\n�����һ������������������������Ǹ�û�õļһ�䵱�����²ݰ�����Ȼ�ѳɴ�����\nһ������ɫ��΢���Բ�᣺�ɳ���û����ʯ���̫��Ѩ�У�\n����������ǳǳ�ķۺ�������ǰ������������\n��������Ϸ���������һ������߾����Ƴ����롣\n�����һ��ϤϤ�������ƺ����˽���Զȥ��\n\n"NOR,ob);

				if (!REWARD_D->check_m_success(ob,"�䵱����"))
					tell_object(ob,HIG"\n�����ݱ����������Ҳʼ��δ����\n���˵ʲô�������ã����ǿ���������ȥ���ϵ����Ӱɡ�\n\n"NOR);

                things = new(__DIR__"obj/cyanneedle");
                things->move(this_object());
                things = load_object("/d/wudang/yinxuanyan");
//                things->shui();
                this_object()->die();
        
        } else {
                command("say �󵨣����һ�װ�����������Ż��Ϸ�\n");
                kill_ob(ob);
        }

        }
}

int leave() {
	if (this_player()->query("class")!="wudang") return 0;
	message_vision(CYN"$Nŭ�����������ļһ���ҹ�����\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵�����߿��ԣ���̫�����е��䵱�ؼ���ͱ��������ˡ�\n"NOR,this_object(),this_player());
	message_vision(CYN"$N˵���Ժ�Ҳ���������ң�\n"NOR,this_object(),this_player());
	return 1;
}


// ���p��dancing_faery@hotmail.com

