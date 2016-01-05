#include <ansi.h>

inherit NPC;
int give_soup();

void create()
{
        set_name("����", ({ "mengpo", "meng"}) );
        set("gender", "Ů��" );
        set("age", 220);
        set("long", "
��˵��������������ʱ����С�������飬�����ʼ����𾭣�������ʱ����
�������ȥ��Ҳ�����뽫����ֻ��һ��һ���Ȱ�˲�Ҫɱ����Ҫ���أ�һֱ��
��ʮһ�꣬��Ȼ�Ǵ�Ů֮����ֻ֪���Լ����ϣ������˳���Ϊ�����š�����
��������ɽ���У���Ϊ��ʱ������֪ǰ�����ţ�����й©�����������������
Ϊ��ڤ֮���ƹ�"YEL"�q��֮��(ask mengpo about soup)"NOR"��
\n");
        set("combat_exp", 5000);
        set("title", WHT"�������ȥ��"NOR);
        set("attitude", "friendly");
		set("no_arrest", 1);
	
		set_temp("apply/astral_vision",1);
		set("chat_chance", 1);
        set("chat_msg", ({
                "���Ŷ���˵�������������˲��ٿ�ɣ�����"YEL"��"CYN"�ɣ���\n",
                "����˵�������ӣ���·ǰ��һ��ɣ���\n",
        }) );
        set("inquiry", ([
                "���̲�":   "���Ǽ������ҩ�ģ���ϧ�����Ѿ�û���ˡ�\n",
                "������" : (: give_soup:),
                "��" : (: give_soup:),
                 "�q��֮��" : (: give_soup:),
                 "�q����" : (: give_soup:),
                "soup" : (: give_soup:)
        ]));
	setup();
	carry_object("/obj/armor/ghost_cloth")->wear();
}


int give_soup()
{
	object obj,me;
	mapping buff;
	int num,death;
	
	me = this_player();
	
	if (!me->is_ghost()) {
		command("say �������ֲ��ǹ���������Ϲ��ʲô��\n");
		return 1;
	}
		
	if (ANNIE_D->check_buff(me,"mengpo-soup")>0 || me->query_temp("marks/ready_incar"))
	{
		command("say ���ӣ����Ѿ��ȹ��ˣ��������·�ɡ���\n");
		return 1;
	}
		
	message_vision("$N���������ַ�Ҩ��һ�����ݸ�$n��\n",this_object(),this_player());
	command("say �������������ȣ��������·��\n");
	message_vision("$Nһ�����ӣ���ཹ�ཱུؽ��q����һ������������������\n",this_player());
	

    // ÿ���ȼ������Ρ������ٶ�Ͷ��Щ��	
	death = me->query("KILLED");
    num = 60 + 5* (death - 2*F_LEVEL->get_level(me->query("combat_exp")));

	if (num < 60) num = 60;
	if (num > 600) num = 600;
			
	buff =
			([
				"caster":me,
				"who": me,
				"type":"mengpo-soup",
				"att":"bless",
				"name":"�����Ļ�",
				"buff1": "mengpo",
				"buff1_c":1,
				"time":  num,
				"buff_msg":""NOR,
			]);
	
	ANNIE_D->buffup(buff);
	me->set_temp("marks/ready_incar",1);
	me->remove_all_killer();	// well, fix that guard problem.
	me->start_busy(2);
	call_out("faint_him", 3, me);
	return 1;
}


void faint_him(object him)
{
	int death, num;
	if (!objectp(him) || !him->is_ghost())	return ;
	him->unconcious();
	him->move(AREA_DEATH"hospital");
	message("vision",
      		"һ����Ӱҡҡ�λε����˽�����һͷ�Ե�������̨�¡�\n", environment(him), him);
	return ;
}	

