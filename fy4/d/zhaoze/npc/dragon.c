inherit SMART_NPC;
#include <ansi.h>

int dragon_shield();
int dragonclaw();

void create()
{
    	set_name(HIR"�һ�����"NOR, ({ "red dragon", "dragon" }) );
        set("race", "��");
        set("gender", "����");
        set("age", 200);
        set("group","giant");
        set("reward_npc", 1);
        set("difficulty", 40);        
        set("long", "
����һ��ȫ���죬�����֮��Ļ������������������ȫ��ɢ���ų��ɫ��
���棬����ݺݵؿ����㣬�ƺ�Ҫ����һ������ȥ��\n");
        
    	set("attitude", "aggressive");
		set("big_boss",1);       
        set("toughness",900);
        
//		set_temp("damage_shield",1);
		set_temp("damage_shield/amount",400);
		set_temp("damage_shield/type","kee");
		set_temp("damage_shield/msg",HIR"�һ������������������$n���û���˹�ȥ��\n"NOR);
    	   	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		80:	(: dragon_shield() :),
        ]) );    	
    	
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: dragonclaw()	:),
        }) );

        set("combat_exp", 2500000);
        set("bellicosity", 3000 );
        
    	set_temp("apply/attack", 400);
    	set_temp("apply/dodge", 400);
		set_temp("apply/parry", 400);

        setup();
		carry_object(BOOKS"force_70");
		carry_object(BOOKS"force_70");
}


int dragon_shield(){
	if (time()>query("dragon/breath")+ 300 && !query_temp("damage_shield")) 
	{	
		message_vision(HIR"\n
�һ������Ӻ�ˮ�����������һ�ڻ�����ȫ��תΪ�ʺ�Ļ�ɫ�����������ʹ��˼�������\n\n"NOR,this_object());
//		set_temp("damage_shield",1);
		set_temp("damage_shield/amount",200);
		set_temp("damage_shield/type", "kee");
		set_temp("damage_shield/msg",HIR"�һ������������������$n���û���˹�ȥ��\n"NOR);
		set("dragon/breath",time());
	}
	return 1;
}

int dragonclaw()	{
	object ob,me,*enemy;
	int i;
	
	ob=this_object();
	ob->set("bite_time",time());
	enemy=ob->query_enemy();
	me=enemy[random(sizeof(enemy))];
	message_vision(HIG"\n�һ��������������ǰצ��Ю����֮�ƣ�Ѹ������$n��ͷ��һץ��\n"NOR,ob,me);
	me->receive_damage("kee",200+random(200),ob);
	COMBAT_D->report_status(me);
	ob->perform_busy(2);
	return 1;
}

void die()
{
        object book;
        object me, owner,*team,*team2;
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
			me = owner;
		} 
		
        if (me){	
        	team = me->query_team();
        	if (team && sizeof(team)){
        		team2 = filter_array(team, (:environment($1)==environment($2):),this_object());
        		map_array(team2, (:REWARD_D->riddle_done($1,"��ɱ����",100,1):));
        	} else
        		REWARD_D->riddle_done(me,"��ɱ����",100,1);
        }
        
        ::die();
}

mapping ob_hit(object ob, object me, int damage) {
	
	int amount;
	object weapon;
	mapping data =([]);
	
	if (damage <=0 || !me->query_temp("damage_shield"))	
		return 0;
	
	weapon = ob->query_temp("weapon");
	if (objectp(weapon) && weapon->query_temp("icy_dipped"))
	{
		
		if (amount <=800)
		{
data["msg"] = WHT"��$N��"+weapon->name() + NOR WHT"�������ǣ��һ������Ļ��ȴ��ǿ���ˣ���\n"NOR;
			me->add_temp("damage_shield/amount",50);
			data["damage"] = 0;
			return data;
		}
	}
	
	if (objectp(weapon) && weapon->query("red_dragon_bane") && me->query_temp("damage_shield"))
	{
data["msg"] = HIW"$N���еĻ��泤�����һ�����ȣ����������������Ļ�һ���������������ϵĻ����ʱ�ҷ�����\n"NOR;
		me->delete_temp("damage_shield");
		data["damage"] = 0;
		return data;
		
	}
	return 0;
		
}
