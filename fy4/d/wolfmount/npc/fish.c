inherit NPC;

void create()
{
        set_name("���������", ({ "fish","colorful fish" }) );
        set("race", "����");
        set("age", 3);
        set("long", "һ����ͷ���Ե�Ұ�㣬���չ��ӳ�£����ϱ任����ʵ���ɫ�������쳣��\n");
	set_skill("dodge", 80);
	set("combat_exp",10000);
        setup();
}