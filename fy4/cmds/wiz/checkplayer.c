#include <ansi.h>

inherit F_CLEAN_UP;
int get_highest_skill_level(object me, int i);

int main(object obj)
{

	object me, *players, *inv, weapon;
	int num, flag, ji_times, weapon_ji, i;
	string arg;
	
	players = filter_array(objects(), (: userp($1) :));
	num = sizeof (players);
	
	log_file("CHECKPLAYER",sprintf("%s��%s������������ݽ������м�顣\n",ctime(time()),geteuid(obj)));
	
	while (num--) {
		me = players[num];
		// 1. Attributes
//	if (wizardp(me))	continue;
		arg = "";
		if (me->query("str") >= 60)	// Unarmed 300+?
		{
			arg = me->query("id")+"����������������Χ(60)��\n";
			
		}
	
		if (me->query("int") >= 60)	// 15+24+3 +10 == 52
		{
			arg += me->query("id")+"�Ĳ��ǳ���������Χ(60)��\n";
		}
	
		if ( me->query("agi") >= 60 
			|| me->query("con") >= 60 || me->query("cps") >= 60 
			|| me->query("kar") >= 60)	// Limit dur,agi,con,cps,kar,fle,spi.
		{
			arg += me->query("id")+"�������������Գ���������Χ(60)��\n";
		}
	
		if (me->query("force_factor") > 140)
		{
			arg += me->query("id")+"��enforce����������Χ(140)��\n";
		}
	
		if (me->query("attr_apply/strength") > 10)	// Yes,I think that all attr_apply should be a negative number till now
		{
			arg += me->query("id")+"��attr_apply/strength����������Χ(10)��\n";
		}
	
		// 2. Combat Exp
		if (me->query("combat_exp") > 10000000)
		{
			arg += me->query("id")+"�ľ��鳬��������Χ(10M)��\n";
		}
	
		// 3. Skill level
		if (get_highest_skill_level(me,0) > 300)
		{
			arg += me->query("id")+"����߼��ܳ���������Χ(300)��\n";
		}
	
		// 4. Max gin/kee/sen, Could player reach/over 40K in 4.1?
		if (me->query("max_gin") > 20000 || me->query("max_kee") > 25000 
			|| me->query("max_sen") > 20000)
		{
			arg += me->query("id")+"�ľ����񳬹�������Χ(25000/20000)��\n";
		}

		if (me->query_temp("apply/attack")> 200 || me->query_temp("apply/damage")> 200
			|| me->query_temp("apply/dodge") || me->query_temp("apply/parry")>200 )
		{
			arg += me->query("id")+"�Ĺ�����/�˺����ȳ���������Χ����������Perform��BUG���𣩡�\n";
		}
		
		// ji bug check
		
		if (me->query("created_item")) {
			if (mapp(me->query("ji")))
				ji_times = sizeof(me->query("ji"));
			inv = all_inventory(me);
//			write(sprintf("%O\n", inv));
			for (i=0;i<sizeof(inv);i++){
				if (inv[i]->query("base_damage") && inv[i]->query("owner")) {
					weapon = inv[i];	
					if (objectp(weapon)) {
						weapon_ji = weapon->query("ji_times");
						if (ji_times != weapon_ji)
							arg += me->query("id")+"������������"+ji_times+"�������˺���"+weapon_ji+"�����ϡ�\n";
					}
				}
			}	
		}
	
		if (sizeof(arg)) {
			write(arg);
			log_file("CHECKPLAYER",arg);
			flag = 1;
		}
	}			
	if (!flag)	{
		write("���ͨ����δ�����쳣��\n");
		log_file("CHECKPLAYER","���ͨ����δ�����쳣��\n");
	}
	return 1;
}


int get_highest_skill_level(object me, int i)
{
    int loop;
	int flag,lv=0;
	mapping skl,map;
	string *sname,*mapped;
	
	skl = me->query_skills();
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = me->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
			if (skl[sname[loop]] > lv)
				lv = skl[sname[loop]];
	}
	return lv;
}


int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	checkplayer[0m
[0;1;37m����������������������������������������������������������������[0m   
 
������Ե�ǰ���ߵ������һ���ܻ����ļ�����
��������ԡ������񡢹����������ܵȣ�����¼�ڰ���
������ζ��쳣��������жϣ�������ʦ��ְ���ˡ�
�����������Դ�����á�

[0;1;37m����������������������������������������������������������������[0m   
 
HELP
);
        return 1;
}
