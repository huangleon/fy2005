inherit NPC;

void create()
{
	set_name("���ʵ�", ({ "kao guan","kaoguan"}) );
	set("title", "���⿼��");
	set("gender", "����" );
	set("age", 47);
	set("int", 26);
	set("NO_KILL","ɱ�����������Ǿ�û�ط�ѧ�����ˡ�\n");
        set("skill_public",1);
        
        set("long",
		"���ʵ��Ǹ���ѧ���ŵ����⿼�٣�������ʱ�����й����ˣ�����\n"
		"��Ϊ����ϲ�������˲�Ը���٣����ʵ��Լ࿼Ϊҵ�������Ըѧ\n"
		"���ʵ����ǻ�̵ġ�
		(skills kaoguan)
		(learn literate from kaoguan with 1)\n");
		
	set("attitude", "peaceful");
	
	set_skill("literate", 40);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


int recognize_apprentice(object ob)
{
	return 1;
}
