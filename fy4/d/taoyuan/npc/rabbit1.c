inherit NPC;

void create()
{
        set_name("Ұ��", ({ "rabbit" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", 
"һֻ��β�͵�Ұ�ã�β����һ�̵�����̶�ߺ�ˮ�����������׾Ϳ���ץ(catch)����\n");
        set("max_kee", 90);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
		set("NO_KILL","��ô�ɰ������ӣ����ǲ�Ҫɱ�˰ɣ�����ɽʲô��ȥ���������ģ�\n");
        set_skill("dodge", 100);

        setup();
}
