inherit NPC;

void create()
{
	set_name("����", ({ "mouse" }) );
    	set("race", "Ұ��");
        set("altitude","aggressive");
        set("age", 1);
        set("long", "��ֻ����������ͷ�ˣ�����ë��ѩ�ף���ֻ�۾������̹⡣ \n");
        set("combat_exp",50000);
        set("attitude", "aggressive");      
        set_skill("dodge", 100);        
        set_temp("armor", 50);

    	setup();
}


void die(){
       	object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner = me->query("possessed")) {
		me = owner;
	} 
        if (objectp(me))
		QUESTS_D->special_reward(me,"��ʨ���");
    	   
    	::die();
}