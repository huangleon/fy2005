inherit NPC;
#include <ansi.h>
int tongqian();

void create()
{
	set_name("�ҳ���", ({ "fortune teller","teller" }) );
	set("gender", "����" );
	set("age", 45);
	set("title",HIY  "�����Ѳ�"NOR);
	set("long",	"��λ�������Ѳ������ҳ��������۹��ܵ������㡣\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
		
	set("inquiry", ([
            "����ͭǮ" : (: tongqian :),
             "ͭǮ" : (: tongqian :),
              "coin" : (: tongqian :),
   	]));
   	
   	set("max_force",1000);
   	set("force", 1000);
	
	set_skill("unarmed",250);
	set_skill("dodge",50);
	setup();
	carry_object(__DIR__"obj/daopao")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(4) ) {
		case 0:
message_vision("$N��$n˵������ӡ�÷��ڣ�ɲ��͸��ͥ�����죡����֮��һ����ʬ��ͷ��\n",this_object(),ob);
			break;
		case 1:
message_vision("$N��$n��Цһ�����㻹��ȥ���ڹײİɣ�\n",this_object(),ob);
			break;
		case 2:
message_vision("$N����$nһ�ۣ�һ�Ҵ�С���ٶ����ˣ�������\n",this_object(),ob);
			break;
                case 3:
message_vision("$N���������˵������ô�ᶪ��ʦ�����ı���ͭǮ��\n",this_object(),ob);
                        break;
	}
}

int accept_object(object who, object ob)
{
        if((string) ob->query("marks") == "special_green_coin")
        {
         //       who->set("marks/green_coin",1);
				REWARD_D->riddle_set( who,"��̽����",1);
				tell_object(who,"�ҳ��ɵ����ã�������ҵ���ͭǮ����������������һ�ԣ�\n");
				tell_object(who,"�������ɷ�����죬��һ��Ҫ������֮�ڶ��ڹײģ����ܶ����һ�٣�\n");
                return 1;
        }
        return 0;
}

int tongqian() {
	message_vision("$N˵��ͭǮ��ʦ�����������������õģ������ϴδӳ������������Ҳ����ˡ�\n",this_object());
	message_vision("$N˵:����������һ�������һ������ú���һ��!\n", this_object());
	return 1;
	}
	
	