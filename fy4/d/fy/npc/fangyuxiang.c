#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "fang yuxiang", "fang" }) );
        set("long","��λ�����������ӷ���ɵ����á�\n");
        set("attitude", "heroism");
		set("title", HIW "������"NOR);
        
		set("gender", "Ů��");
		set("per", 30);
		set("age",16);
        set("combat_exp", 300000);

        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
		set_temp("apply/dodge", 70);
		set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/move", 100);

        setup();
        carry_object(__DIR__"obj/goldcloth")->wear();
}


int accept_object(object me, object obj)
{
		object real;
		
		if( (string) obj->query("name") == "��ɲ��")
		{
        	if (REWARD_D->riddle_check(me,"��ȡ��ɲ") !=4)
        	{
        		command("say ԭ������͵����ɲ�ƣ������ˣ�����÷�����ϲ���Ź���ġ�");
        		return 0;
        	}
        	
        	if (obj->query("fake"))
        	{
        		command("grin");
        		command("say ����ɲ����ʵ�Ǽٵģ��������ǻ����ٿ��鿼���㣬����ʵ��ûʱ�䡣");
				command("say ���Ծ��ܻ�ͷ��β��Ҳֻ�ܲݲ��ճ��ˡ�");
				command("sigh");
				command("say �������ȥ�ɡ�");
				REWARD_D->riddle_set(me, "��ȡ��ɲ", 5);
				real = new(BOOKS"skill/qiankunwuxing_50");
        		if(!real->move(me))
					real->move(environment());	
        		return 1;
			}
			
			command("say �㻹�ǿ������������÷���ϰɣ��������ǲ���Ź���ġ�");
			return 0;
		}
		return 0;
}

