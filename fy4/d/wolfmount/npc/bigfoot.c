#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("������", ({"liu jinlian","liu"}) );
        set("gender", "Ů��" );
        set("nickname", HIM "ĸɫ��"NOR);
        set("long", "��Ů�˵�һ˫�ż�ֱ��������С����Ѫ�����ƺ���ʱ׼������һ�ڸ�����ȥ��\n");
 	set("attitude", "friendly");

	set("age", 36);
	
        set("combat_exp", 1000000);
        
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        	"���������Ŵ������ݹ�Ц����Щ���˶��ǹ������ҵ��������������\n",
        }) );
        setup();
        carry_object(__DIR__"obj/redskirt")->wear();
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
	if (ob->query("gender") == "����" && ob->query("combat_exp") > 1000000 )
	{
		message_vision("$N������ͻȻ��$n���˹�ȥ�������Ϲ����ˣ�������������ɡ���\n", this_object(),ob );
		this_object()->kill_ob(ob);
	}
	return;
}
