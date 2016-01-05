#include <ansi.h>
#define MONEY_VALUE 1000
inherit NPC;

void create()
{
	set_name("С����", ({ "little fatman","fatman" }) );
	set("gender", "����" );
	set("title", HIG"���ִ���"NOR);
	set("age", 26);
	set("long",
		"����һﳤ�û�����ü��Ŀ�㣬���ǿ���ȥ�ܸ���һ�ֻ����ĸо�������\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
    	set("chat_chance", 1);
	set("chat_msg", ({
                "С���Ӳ�м�������̸��ܡ������ӵ������߽��������ִ��ٵ���ͷ�Ǹ���֪��\n˭�˲�������\n",
                "С�������صĵ������ǣ�֪��������˭��˵���������㣬���Ӿ����˼���\n�˼��˰������֡��ġ��������������졫��ʹ����������\n",
                "С����ͻȻ������ó�һ�������������������С������װ���С�ܵܣ�����\n���ҵĿ�����࣡\n",
                "С����̾�˿��������˵�˵�������Ҥ�ӹ���ˣ���ͷ��ת���飬�����ð���\n�����˲ųɡ���\n",
        }) );
	set("chat_msg_combat", ({
        	"С���Ӹ߽е������̸��ܡ����������Ӵ�ܣ������ӽ�ѵ��ѵ�㡫��\n",
	}) );

    set_skill("move", 100);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
    set_skill("unarmed", 20);
	set_skill("wuzheng-force",220);
        set_skill("literate", 200);
        set_skill("meng-steps",220);
	map_skill("force", "wuzheng-force");
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps"); 
	setup();
    carry_object("/d/fugui/npc/obj/m_cloth2")->wear();
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) 
        {
                case 0:
			message_vision("$Nб����$nһ�۵�����֪���������������Ұɣ���������á�\n",this_object(),ob);
                        break;
                case 1:
			message_vision("$N��$n�ʵ���֪�����˭PK�����𣿸��ҵ�Ǯ���Ҹ����㣡\n",this_object(),ob);
                        break;
                case 3:
			message_vision("$N������Ķ�$n˵����ǧ��¥�Ĺ������Ǽ��ˣ�Ҫ��Ҫ�Ҹ���ָ����·��\n",this_object(),ob);
                        break;
                case 4:
			message_vision("$Nҡҡͷ���޹���˵�����Ҹɻ�����֣��������ҡ���ү������ͬ����\n�ò��ã�\n",this_object());
                        break;
                case 5:
			message_vision("$N͵͵Ц��˵�������������ұ��ֲ���������������ҳԷ���\n",this_object(),ob);
                        break;
                case 6:
			message_vision("$N������$n˵�������Ƴ�����õĴ��֪����˭���������������¾���\n�����ҵ�����֮����\n",this_object(),ob);
                        break;
                case 7:
			if(ob->query("gender") == "Ů��")
			{
				command("lure");
				command("say ��λ" + RANK_D->query_respect(ob)+ "�������û�пհ�����ҹʱ���ǲ��Ǹе���įѽ�����Ұ�ο��ο��\n����Ҫ������İɣ�\n");
			}
			else
			{
				command("heihei");
				command("say ���ǣ���û��ƯƯ���ý��ܰ����еĻ������Ӹ���㽱����\n");
                        }
                        break;
                case 8:
			message_vision("$N������$n�ļ��˵������������ϳ��¼��˲�����Ȥ�Ķ�����������һ\n��ȥ������Σ�\n",this_object(),ob);
                        break;
                case 9:
			message_vision("$Nί������$n˵����ʲô��������ǰ����ɱ���ˣ����ڱ�����ɱ��������ܰ���\n",this_object(),ob);
                        break;
        }
}

int accept_object(object me, object obj)
{	
	object birdcase;
	
        if( (int) obj->value() >= (MONEY_VALUE+ random(MONEY_VALUE)) )
        {
        	if (me->query("gender") == "Ů��")
        	{
        		command("qsister "+me->query("id"));
        		message_vision("$N��ƤЦ����˵�����ù��գ�\n",this_object());
        	       	message_vision("$N���������ó�С��Ȼ��ѿյ������ݸ�$n��\n",this_object(),me);
        	}
		else
		{
			command("kick "+me->query("id"));
        	       	message_vision("$N�޺޵�˵��Ҫ����ȱǮ��Ҥ�ӣ����ӲŲ����ء�\n",this_object());
        	       	message_vision("$N���������ó�С��Ȼ��ѿյ������ݸ�$n��\n",this_object(),me);
        	}
        	birdcase = new(__DIR__"obj/birdcase");
        	if(birdcase)
        	birdcase->move(me);
        	return 1;       
        }
	else
	{
		command("heihei");
        	command("say ��л��λ" + RANK_D->query_respect(me) +"���´�����Ⱦƣ�");
        	return 1;
        }
	return 0;
}
