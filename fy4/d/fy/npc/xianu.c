// worker.c

inherit NPC;

void create()
{
        set_name("����Ů��", ({ "naked girl", "girl" }) );
        set("title", "һ˿����");
        set("gender", "Ů��" );
        set("age", 29);
        set("long", "����ˮ����Ц����Ư��Ů�ˣ������Һ죬����������£������̺��
������һ���ʢ���š�����\n");
        set("combat_exp", 17000);
        set("attitude", "friendly");
        
        set_skill("unarmed", 10);
        set_skill("parry", 25);
	set_skill("dodge", 100);
	set_skill("throwing", 50);
	
	setup();
}

