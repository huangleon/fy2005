// qinge.c

inherit NPC;

#include <ansi.h>
void create()
{
    set_name("�ظ�", ({ "qin ge", "qin"}) );
	set("gender", "����" );
	set("age", 25);
        set("title","ɽ�� ����");
	set("nickname",HIW "����"NOR);
	set("long",
"������ϵ��������˿���۾������й⣬�����þ��㲻̫Ӣ��Ư������ƾ������
�ɣ����㹻��Ů��һ�Ӷӵİݵ������ڶ��ӵĿ���¡�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "�ظ��ˬ�ش�Ц������Ҫ�ľͶĸ�ˬ�죬���򻹲���ؼұ�����ȥ��\n",
	    "�ظ���ɫ����˭Ҫ����ɽ�����͵���ȫ�����Լ����͵�Ҫ���µ����ľ���
��������Ҳ�������ǣ�\n",
    }) );
        set("inquiry",  ([
                "ɽ��" : "��ĳ�˵���Ϊ��ɽ����ҵ�������ٱ���ǧ����������Ѫ��Ҳ�������ǣ�\n",
                "shanliu" : "��ĳ�˵���Ϊ��ɽ����ҵ�������ٱ���ǧ����������Ѫ��Ҳ�������ǣ�\n",
                "Ѫ��ϭ": "Ѫ��ϭ���˽Գư�һ���ĺڵ����ɣ�����С�ӡ�\n",
                "questnpc": "Ѫ��ϭ���˽Գư�һ���ĺڵ����ɣ�����С�ӡ�\n",
                "������": "���������������ټ��������۵�ƾ�ţ����ǵ��������ν����ʮָ��\n",
	        "qinglong-ling": "���������������ټ��������۵�ƾ�ţ����ǵ��������ν����ʮָ��\n",
                ])                      );

	set("combat_exp", 20000000);
	set("attitude", "friendly");
	set("per",30);
	set("str", 40);
	set("force",1000);
	set("max_force",2000);
	set("force_factor",50);
	set_skill("dodge",100);
        set_skill("blade",200);
        set_skill("parry", 200);
	setup();
	carry_object("obj/armor/cloth")->wear();
}

int accept_object(object me,object ob)
{
	string org_attri;
	if (ob->query("id") != "qinglong-ling")
		return 0;
	if (me->query("organization/org_attribute") != "��")
	{
		message_vision("$N���ֵ�����λ"+RANK_D->query_respect(me)+"�ŵ��ȳ��������嵨�������壬������������������ĳ�������ְѾ��۵�����ϧ��ϧ����\n",this_object());
		QUESTNPC_D->quest_reward(me,ob,"��");
		return 1;
	}
	if (ob->query("killer") && ob->query("killer") == me)
	{
		message_vision("$NĿ����棬��ϸ������$n������Ц�������������������ף�ָ�տɴ���\n",this_object(),ob);
		
	}else
	{
		message_vision("$N����$n����Ȼ�������������������£���ȵ���ռ֮��������������Ϊ�����ɷ�����̹���������������ġ�\n",this_object(),me);	
	}
	QUESTNPC_D->quest_reward(me,ob,"��");
	return 1;
}

