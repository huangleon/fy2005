// Can't Parry.
// ��ͨ����ר�� *cat
// ��pots
// coeff = 180��200�� 360 enable ����ittouryu 150*2=300 enable��
// book ��˼���ף�study 0 - 50, learn 100 - 150, research 150 - 200.
// perform ���콣�� Ω��ͨ���տ��ã�Ч����xiaodao�ҹ���
// ��������������������iron-cloth������PB/DB/OHB,1-4hit busy 2-3��

inherit SKILL;
void setup() {
	set("name","��а����");
	set("effective_level",180);
	set("type","sword");
	set("difficulty",300);
	set("usage/sword",1);
	set("skill_class","npc");
	action = ({
        ([      "action":               
"$N����$wббһ����һʽ��һ����ã������һƬ�⻪����$n",
                "damage":               70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��Ȼ��ü������$wһת��ʩ����˫Ŀ�޹⡹�������㽣������$n",
                "dodge":                -140,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ������$w������ɻ�Ϯ��$n�����Ǿ�а���еġ�����Ե����",
                "parry":                -210,
                "damage":               210,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ����Ȧ��һ�ƺ�������ǵض�������һʽ���Ǿ�а���š��ĺ�Ϊ�ҡ�",
                "dodge":                280,
                "parry":                -280,
                "damage":               280,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһʽ����Ȳ�ʳ��������һ����˳��һ�����������˷ִ磬ȴ�����������",
                "dodge":                -350,
                "parry":                350,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ��$w�����ֽ��У����汯�ݣ�һʽ�������ϡ���ֱײ��$n",
                "dodge":                -420,
                "parry":                -420,
                "damage":               420,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��̾һ����ʹ��ɱ�š����Ϸ�˪��������$wһ�㣬�Ѿ���ȥ�˽��⣬ֻ��һ�ѷ�\n���������޻���$wƽƽ����$n",
                "dodge":                490,
                "parry":                490,
                "damage":               490,
                "damage_type":  "����"
        ]),
});

}

int effective_level(object me)
{
	
	if (me && userp(me))
	{
		if (!me->query("class"))
			return 180;
	}
	return 80;
}

int skill_difficulty() {
	
	object me = this_player();
	if (me && userp(me)) {
	if (!me->query("class"))
		return 300;
	}
	return 700;	
}

/*
int valid_learn(object me)
{
	if( me->query("class") ){
		return notify_fail("���Ż�֮������޷�ѧϰ��а������\n");
	}
 	return ::valid_learn(me);
}
*/

mapping query_action(object me, object weapon)
{
	int i,level;
	level   = me->query_skill("demosword",1);
	if(level < 29) level = 29;
	for(i = sizeof(action); i > 0; i--)
		if(level >= i * 29)
			return action[random(i)];	// to get the 7th'hit,research 200->203.
}

int help(object me)
{
	write(@HELP   
�����콣�󡻣�zhutianjianzhen��
��Ҫ170����а������150��Т����
������Щ����Ĺʵ����ë���һ��ϡ�У�Ҫ������Ѱ��������ʽ��
������Ȼ������������ѡ����к����߽������������Ҳ���ƴ�ն���
ָ�����Ϲ�ʱ����ܩ����ʦ��������һʽ��������Ƶ���ߵĴ󽫷�󣬽�
����������ֻء�Ȼ�����򵥵���һ�仰�����Ǻ��˶ԡ����콣������
����֪������һ�е�һ�У����Ƕ�����Զ��û����ʷ������֮�С�

1-4����������æ��2-3�غϡ�
����Ӳ�����˺�����Т���ȼ���ء�

ע����ͨ����ϵ��Ϊ180 ����Ϊ80
��ͨ����ѧϰ�Ѷ�Ϊ300 ����Ϊ700
����ͨ����ʱʹ�ã�����æ�����Ӷ��غϡ�

HELP
    );
    return 1;
}


/*Edit By Hippo 2009.11*/
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

