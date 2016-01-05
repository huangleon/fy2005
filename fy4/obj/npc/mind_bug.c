// mind_bug.c

inherit NPC;

void create()
{
        set_name("�����", ({ "mind bug", "bug" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", 
"����һֻ���޵��˵������˼�����Ĺ���棬���ס�˵Ļ��ǡ�\n");
        
        set("str", 24);
        set("cor", 26);

        set("max_kee", 140);
        set("max_gin", 250);
        set("max_sen", 600);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        
        if( this_player() ) {
                set("combat_exp", (int)this_player()->query_skill("spells", 
1) * 500);
                set("bellicosity", this_player()->query("bellicosity"));
        }

        set_temp("apply/attack", 30);
        set_temp("apply/armor", 10);

        setup();
}

void die()
{
        string owner;
        object owner_ob, killer, rkiller;

        owner = query("owner");
	if(stringp(owner))
        if( objectp(owner_ob = find_player(owner)) ) {
		killer = (object)query_temp("last_damage_from");
	        if(!objectp(rkiller=killer->query("possessed"))) rkiller = killer ;
                if( (killer != owner_ob) && (rkiller != owner_ob)) {
                        tell_object(owner_ob, 
"��Ĺ���汻��ɱ���ˣ�\n�����һ��������ת....\n");
                        owner_ob->unconcious();
		} else if (owner_ob->query_skill("spells",1)<=200) {
			tell_object(owner_ob, "��ɱ������Ĺ���棬���Ҵ�������һЩ�����ĵ���\n");
			owner_ob->improve_skill("spells", random(owner_ob->query("spi")/2)+1);
		} else tell_object(owner_ob,"��ɱ������Ĺ����ޣ�������������Ѿ������ɴ�����ˡ�\n");
        }
        ::die();
}
 
