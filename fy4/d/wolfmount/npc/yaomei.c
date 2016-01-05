#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("������", ({"liu yaomei","yaomei"}) );
        set("gender", "Ů��" );
        set("nickname", HIM"ɫ��"NOR);
        set("long", "����һ��������⣬����΢¶��������Ů��ɫ���Եض����㡣\n");
 		set("attitude", "friendly");
		set("age", 18+random(10));

        set("combat_exp", random(600000)+200000);
        create_family("��ɽ", 4, "����");
        set_skill("blade", 50+random(20));
        set_skill("parry", 50+random(20));
        set_skill("dodge", 50+random(20));
        set_skill("move", 50+random(20));
        set("chat_chance", 1);
        set("chat_msg", ({
        	"�����ÿ���Ц�����������ﲻ������ĥ��Щ��ô������ū�����ү���ȴ����ɣ�\n",
        }) );
        setup();
		carry_object(__DIR__"obj/pink_cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object *inv;
	int i;
	if (!ob || environment(ob)!=environment(this_object()))	return;
		
	if ((string)ob->query("gender") == "����")
	{
        message_vision(MAG"$N������˿����$n��˫��Ħ�����Լ��⻬���ظ�����߽��������ɰ�����ѽ��
��ѽ�������ҹ�������֮�֡�����\n"NOR, this_object(),ob );
        if ((int)ob->query_cps()<random(15) && !ob->query_temp("sleeped")){
   			message_vision("$N������ˮֱ���������Ϳ������ȥ��\n", ob);
			ob->set_temp("sleeped",1);
			ob->set_temp("disable_inputs",1);
			ob->add_temp("block_msg/all",1);
			ob->set_temp("is_unconcious",1);
			ob->set("disable_type",HIG "<˯����>"NOR);
			inv = all_inventory(ob);
			if(sizeof(inv)) {
				for(i=0; i<sizeof(inv); i++) {
					inv -= ({ 0 });
					if(sizeof(inv)) {
						if(inv[i]->query("equipped")) {
							inv[i]->unequip();
						}
					}
				}
			}
	  		call_out("wake", 8, ob);
	  		return;
	  	}
	  	else
	  	{
	  		message_vision("$Nŭ��һ������Ů��������\n", ob);
	  		return;
	  	}
	  }
	  return;
}


void wake(object ob)
{
	if (!ob)	return;
		
	ob->delete_temp("disable_inputs");
	ob->delete("disable_type");
	if (ob->query_temp("block_msg/all")>=1)
	    	ob->add_temp("block_msg/all", -1);
	ob->delete_temp("is_unconcious");
	if(!ob->is_ghost())
	{
        message_vision(CYN"$N�������۾����پ����������ವģ���ͷһ�������ڿ㶼û�ˡ�\n", ob); 
        message_vision("$N���ᴩ����ȹ����������ū��ʲô�����˹��ӣ������㡭��Ҫ��ū�Ҹ����ϡ�\n"NOR,this_object());
		return;
	}
	return;
}
