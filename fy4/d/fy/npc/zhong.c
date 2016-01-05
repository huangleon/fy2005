inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
string quest();
void create()
{
          set_name("�����", ({ "zhong liuxiu","zhong" }) );
        set("gender", "����" );
        set("age", 31);
        set("title", CYN"�������"NOR);
        set("long","��λ�ϰ���Ƿ��Ƴ��з�������ɷ��˳�������������㡣\n");
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set("NO_KILL","�����˵��֪����������ϱ������˵���ү����Ҷ��֣�\n");
        set("vendor_goods", ([
                __DIR__"obj/painting1" : 50,
                __DIR__"obj/painting2" : 50,
                __DIR__"obj/painting3" : 50,
                __DIR__"obj/painting4" : 50,
                __DIR__"obj/painting5" : 20,
                __DIR__"obj/painting6" : 20,
        ]) );
        
        set("inquiry", ([
	       	"����": 	(: quest :),
	       	"����": 	(: quest :),
	       	"zhaoren": (: quest :),
	       	"job": (: quest :),
         ]) );
        
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        if ( ob->query("gender") == "����")
        {
                if (!random(4))
                        message_vision("$N����"+ob->name()+"��ӭ����Ц������λ"+RANK_D->query_respect(ob)+"�����µ����˳�ԡͼ���ˣ��뿴����\n",this_object(),ob);
        }
        else
        {
                if (!random(4))
                        message_vision("$N����"+ob->name()+"��ӭ����Ц������λ"+RANK_D->query_respect(ob)+"��������ȥ��ɽ�������������µĳ���˧�����뿴����\n",this_object(),ob);
        }
        return;
}

void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/painting1" : 50,
                __DIR__"obj/painting2" : 50,
                __DIR__"obj/painting3" : 50,
                __DIR__"obj/painting4" : 50,
                __DIR__"obj/painting5" : 20,
                __DIR__"obj/painting6" : 20,
        ]) );
}

string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	object me = this_player();
	
	if (me->query("quest/short") == "ȥ����㴦�������˵��¶�")
	{
		if (me->query("quest/duration") == 411)	// ��С��
		{
				n=1+random(3);
				me->set("annie_quest/name","�����ð�ɱЫ��");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"�������ð�ɱXXX"+WHT"��Ы��"NOR);
				me->set("annie_quest/target","Ы��");
				
				me->set("quest/short", WHT"�������ð�ɱ"+ n + WHT"��Ы��"NOR);
				me->set("quest/location", "������");
				me->set("quest/difficulty",n*30);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*180);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());
				arg= "��ʵ����ɽ�����ˣ���Ǯ����������ѵ��Ы��ɱ�֣���ȥ��ɱ������\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 412)	// ��С��
		{
				
				n=1+random(3);
				me->set("annie_quest/name","�����ó�������");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"�������ð�ɱXXX"+WHT"��������"NOR);
				me->set("annie_quest/target","������");
				
				me->set("quest/short", WHT"�������ð�ɱ"+ n + WHT"��������"NOR);
				me->set("quest/location", "������");
				me->set("quest/difficulty",n*70);	// ÿ��һ���Ͷ�50% reward
				me->set("quest/duration",900+n*180);	// ÿ��һ���Ͷ�2����
				me->set("quest_time",time());
				arg= "����ɽ�������Ǯ�����ã�������ȥ��ɱ���������µ��ˡ�\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}
		
		if (me->query("quest/duration") == 431)	// ��С��
		{
				n=1+random(3);
				me->set("annie_quest/name","��Ǯ����֮��ʬ");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"����Ǯ����ɱ��XXX"+WHT"����ʬ"NOR);
				me->set("annie_quest/target","��ʬ");
				
				me->set("quest/short", WHT"����Ǯ����ɱ��"+ n + WHT"����ʬ"NOR);
				me->set("quest/location", "��Ǯ����");
				me->set("quest/difficulty",n*50);	// ÿ��һ���Ͷ�50% reward
				me->set("quest/duration",900+n*180);	// ÿ��һ���Ͷ�2����
				me->set("quest_time",time());
				arg= "��Ǯ����������ҩ�ˣ������ȥ����������ʬ��\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}
		
		if (me->query("quest/duration") == 432)	// ��С��
		{
				n=1+random(3);
				me->set("annie_quest/name","��Ǯ����֮����");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"����Ǯ����ɱ��XXX"+WHT"������"NOR);
				me->set("annie_quest/target","����");
				
				me->set("quest/short", WHT"����Ǯ����ɱ��"+ n + WHT"������"NOR);
				me->set("quest/location", "��Ǯ����");
				me->set("quest/difficulty",n*70);	// ÿ��һ���Ͷ�50% reward
				me->set("quest/duration",900+n*180);	// ÿ��һ���Ͷ�2����
				me->set("quest_time",time());
				arg= "��Ǯ����������ҩ�ˣ������ȥ�����������⡣\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 433)	// ��С��
		{
				n=1+random(3);
				me->set("annie_quest/name","��Ǯ����֮��ʬ����");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"����Ǯ����ɱ��XXX"+WHT"����ʬ����"NOR);
				me->set("annie_quest/target","��ʬ����");
				
				me->set("quest/short", WHT"����Ǯ����ɱ��"+ n + WHT"����ʬ����"NOR);
				me->set("quest/location", "��Ǯ����");
				me->set("quest/difficulty",n*100);	// ÿ��һ���Ͷ�50% reward
				me->set("quest/duration",900+n*240);	// ÿ��һ���Ͷ�2����
				me->set("quest_time",time());
				arg= "��Ǯ����������ҩ�ˣ������ȥ����������ʬ���⡣\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}
		return "�������ûʲô���飬�㲻��û�����ʦ���ݲ�ɡ�\n";	// error mark.
	}
	else
		return "action�����Ц��˵����������еúܣ������˶���";
	
	return " ";
}
