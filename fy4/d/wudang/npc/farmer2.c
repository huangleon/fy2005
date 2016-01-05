#include <ansi.h>
inherit NPC;

string quest();

void create()
{
    	set_name("��ũ", ({ "old farmer", "farmer" }) );
    	set("gender", "����");
    	set("age", 46);
    	set("long",
        	"һλ�����ʮ��ũ��\n"
		);
		
		set("inquiry", ([
	       	"����": 	(: quest :),
	       	"����": 	(: quest :),	
	       	"nanti":	(: quest :),	
	       	"nanshi": (: quest :),
	       	"difficulty": (: quest :),
	       	"job": 	(: quest :),
         ]) );
		
		
		
		set("combat_exp",2000);
		set("NO_KILL","��ô�ϵ���ͷ���������������ɡ�\n");
		set_skill("blade", 10+random(50));
    	setup();
    	carry_object(__DIR__"obj/liandao")->wield();
    	carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
    	object          book1;
    	object 	    book2;
    	if( ob->name() == "����") {
        	say("��ũ�ӹ�������˵������л��λ" + RANK_D->query_respect(who) + "�����������ء�\n");
        	if( present("rice", ob) && present("qing cai", ob)) {
            		say("��λ" + RANK_D->query_respect(who) +"����ϰ��֮�ˣ��Ȿ����ܶ������ã������¡�\n");
            		book2 = new(BOOKS"skills_31");
            		if (!book2->move(who))
            			destruct(book2);
            		if (QUESTS_D->verify_quest(who,"�䵱�ͷ�")) 
            			QUESTS_D->special_reward(who,"�䵱�ͷ�");
            		return 1;
        	}
        	else {
            		say("��ũ�򿪷������˿���˵�����ף���λ" + RANK_D->query_respect(who) + 
                		"���ҵ���Ц������û�з���ѽ��\n");
            		return 1;
        	}
    }
    return 0;
} 

/*
	�׻���	400k
	��β����	450k
	��ë���� 350k
	������ 200k
	�һ����� 500k
	��ɽ�� 300k

	С¹ 	50k
*/

string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	int x;
	object me = this_player();
	string *list2=({
	"�׻���",
	"��β����",
	"��ë����",
	"�һ�����",
	});
	
	string *list1=({
	"��ɽ��",
	"������",
	});
	
	if (me->query("quest/short") == "ȥ�䵱��ũ���������")
	{
		if (me->query("quest/duration") == 401)	// ��С��
		{
				i = random(2);
				n=1+random(3);
				me->set("annie_quest/name","�һ��ֳ�С��"+list1[i]);
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"���һ�����ɱXXX"+WHT"��"+list1[i]+NOR);
				me->set("annie_quest/target",list1[i]);
				
				me->set("quest/short", WHT"���һ�����ɱ"+ n + WHT"��"+list1[i]+NOR);
				me->set("quest/location", "�һ���");
				me->set("quest/difficulty",n*30);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*60);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());
				arg= "�һ������Ұ��ÿ�����Ͼͳ�����̣ׯ�ڣ�����ǰȥ��ɱ����"+list1[i]+"��\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 402)	// ��С��
		{
				i = random(4);
				n=1+random(3);
				if (i==3) x=2;
					else x=1;
				me->set("annie_quest/name","�һ��ֳ�Ұ��"+list2[i]);
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"���һ�����ɱXXX"+WHT"��"+list2[i]+NOR);
				me->set("annie_quest/target",list2[i]);
				
				me->set("quest/short", WHT"���һ�����ɱ"+n+ WHT"��"+list2[i]+NOR);
				me->set("quest/location", "�һ���");
				me->set("quest/difficulty",n*50*x);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*240);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());
				arg= "�һ������Ұ��ÿ�����Ͼͳ�����̣ׯ�ڣ�����ǰȥ��ɱ����"+list2[i]+"��\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}

		return "�������ûʲô���飬�㲻��û�����ʦ���ݲ�ɡ�\n";	// error mark.
	}
	else
		return "action��ũЦ��˵����������еúܣ��Ķ���ʲô���¡�";
	
	return " ";
}
