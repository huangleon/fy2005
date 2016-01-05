#include <ansi.h>
#include <combat.h>
inherit NPC;
void goaway();
void playgame();
void blade_pfm(object me, object target);

void create()
{
        set_name("ɽ���ٷ��ϴ�", ({ "shanxi laoda","laoda" }) );
        set("nickname","ѧ�չ���");
        set("gender", "����" );
        set("age", 27);
        
        set("long", "��ǿ�������˰̣�����������һ���׺ݶ��Ե������ӡ�");
        set("attitude", "heroism");
        
        set("bellicosity", 1500 );
        set("combat_exp", 10000);
		set("no_lu_letter",1);
		
        set("chat_chance", 50);
        set("chat_msg", ({
		(: goaway :),
        }) );

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
              	(: playgame() :),
        }) );

        set_skill("unarmed", 100);
        set_skill("blade", 160);
        set_skill("dodge", 140);
        set_skill("parry", 150);
        set_skill("move",100);
        set_skill("force",100);
        
        set_skill("demon-steps",100);
        set_skill("demon-blade",120);
        set_skill("demon-strike",120);
        set_skill("demon-force", 100);
        
        map_skill("force","demon-force");
        map_skill("dodge","demon-steps");
        map_skill("move","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        map_skill("unarmed","demon-strike");
        
	    setup();
        carry_object(__DIR__"obj/guiblade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

void goaway()
{
	object ob;
	if (ob=present("li biaotou",environment()) )
	{
		command("grin");
		kill_ob(ob);
		ob->kill_ob(this_object());
		return; 
	}
		
	message_vision("$Nһ�����ڣ���ʧ����Ӱ���٣�\n",this_object());
	destruct(this_object());
}


void unconcious()	{ die();}


void	die(){
	
	string *msg = ({
		"\nɽ���ٷ��ϴ��ڵ�˵���������ˡ��������˰���\n",		
		"\nɽ���ٷ��ϴ��ص�����֪���Ͷ�ѧ�����ˡ�\n",
		"\nɽ���ٷ��ϴ��У������ǣ���ס����\n",
	});
		
	message_vision(HIR""+ msg[random(3)] + "\nɽ���ٷ��ϴ����ˡ�\n"NOR, this_object());
	destruct(this_object());
}

void playgame(){
	
	object *inv;
	object me, target;
	int i;
	int tt;
	
	me = this_object();
	
	if (!random(4)) {
		message("vision", HIR"\n"+me->name()+HIR"һ�в�����¶���˺ô��һ������������\n"NOR,
	        		environment(me), me);
		me->start_busy(2);
		return;
	}
	
	if (random(6))	tt= 1;
		else tt = 0;	
		
	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv);i++){
		if (tt) {
			if (inv[i]->query("id")=="shanxi gangster")
				target = inv[i];
		}
		if (!tt) {
			if (inv[i]->query_temp("protecting"))
				target = inv[i];
		}
	}
	if (objectp(target)){
		switch (random(3)) {
			case 2:		command("say С�ӿ��У������ħ��ʮ��ʽ��"); break;
			case 1:		command("say ����ʹ�����ˣ������ɣ�"); break;
			case 0: 	command("say �ֵ��ǣ�������Щ������̫�����ˣ�"); break;
		}
		blade_pfm(me, target);
	}
}


void blade_pfm(object me, object target){
		
		string msg;
	
		msg = HIY  "\n$N������ͨ���������ħ������ʽһ���ǳɣ�\n��ħ���ѣ�" NOR;
		
		target->set_temp("no_check_pfm_win",1);
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		target->set_temp("skip_damage_record",1);        
        msg = HIY  "ħ�����ɣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "ħ��է�֣�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "������ħ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���죡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���֣�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���ڣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        
        if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record",1);
		}

        me->start_busy(8);
        return;
}
        