inherit NPC;

void create()
{
	set_name("С����", ({ "mouse" }) );
    	set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ��ͷ���Ե�С���� \n");
        set("combat_exp",7000);
   	set("attitude", "aggressive");
        set_skill("dodge", 100);        
        set_temp("armor", 50);

    	setup();
}


