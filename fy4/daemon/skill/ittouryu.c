//mimicat@fy4
//ittouryu.c
inherit SKILL;

void setup(){
	set("name","һ��������");
	set("type","blade");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","ninja");
	set("parry_msg", ({
        	"$nһ�С��з�������Ϊ����������$N�Ĺ��ơ�\n",
		"$nͻȻ�ӻ����ͳ�һ�Ѷ̵���������������һ����ס��$N�Ĺ�����\n",
	}) );
		set("unarmed_parry_msg", ({
    		"$nһ�С��з�������Ϊ����������$N�Ĺ��ơ�\n",
		"$nͻȻ�ӻ����ͳ�һ�Ѷ̵���������������һ����ס��$N�Ĺ�����\n",
	}) );
	action = ({
		([      "action" : 
		"$N˫�ֳֵ����߾ٹ�����ͻȻ��$n����һ�С�����������$w������֮��ֱ��$n��Ҫ����ȥ",
		        "dodge" : 10,
		        "parry" : 20,
		        "damage" : 120,
		        "damage_type" : "����",
		]),
		([      "action" : 
		"$Nһ�С��������͵ػӶ�$w��$n��ͷ���£�$n����һ������$w�ĵ����������ĵ�Ϯ��$n",
		        "dodge" : 17,
		        "parry" : 14,
		        "damage" : 120,
		        "damage_type" : "����",
		]),
		([      "action" : 
		"$N���е�$w���Ⱪ������ᰡ�������һ����ײ��$n",
		        "dodge" : 12,
		        "parry" : 11,
		        "damage" :110,
		        "damage_type" : "����",
		]),
		([      "action" : 
		"$N�Ӷ�$w��һ�С�Ҷ�кϡ��������ǣ���㲻��$n",
		        "dodge" : 80,
		        "parry" : 80,
		        "damage" : 140,
		        "damage_type" : "����",
		]),
		([      "action" : 
		"$N���е�$w��$n�����ļ�϶�������˽�ȥ��$N���е�$w������һ��������ȥ",
		        "dodge" : 70,
		        "parry" : 70,
		        "damage" : 90,
		        "damage_type" : "����",
		]),
		([      "action" : 
		"$N��ͷ���$n��һ����������Ҳ���룬����һ�С����ۡ�$w����������꣬ն��$n���ؿ�",
		        "dodge" : 120,
		        "parry" : 120,
		        "damage" : 120,
		        "damage_type" : "����",
		]),
	});
}

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "���˵ı���" )!= 1) 
		return notify_fail("���ʮ����δ��Ӧת���������书��\n");
	if ((int)me->query("tianfeng/ittouryu")!=1){
		return notify_fail("���ʮ����δ��Ӧ���������书��\n");
	}
	if( (int)me->query("max_force") < 500 ) {
        return notify_fail("�������������û�а취��һ����������\n");
	}
	 return 1;
}*/

int help(object me)
{
	write(@HELP   
һ����������ʵ�ǵ��������ǽ�����
	
�������С���gobankiri��
��Ҫ100��һ������������һ�����ʴ������������������ܴ����򹥻�
����һ�У�����ʱ��С����˫����ƴ���������æ�����֡�����æ�����֡�
��ע����ǣ����۳ɰܣ�60�����޷���ͬһ���������������ĳ��ԡ�

���ٹ�ҹ�񡻣�hyakki��
��Ҫ150����һ�����������þ�����ɱ���������֣������е�����Ϊ
	���������پ���һ��ɱ��
	���ߣ�����ÿ��������һ��
���е���Խ�࣬����æ��Խ�̣����߻�����գ�����æ�Ұ��֡�
�������������ϣ��Է����������æ�����֡�
HELP
    );
    return 1;
}
