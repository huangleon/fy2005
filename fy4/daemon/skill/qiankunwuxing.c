inherit SKILL;
void setup() {
	set("name","Ǭ������");
	set("type","magic");
	set("usage/magic",1);
	set("skill_class","yinshi");
	set("effective_level",100);
	set("difficulty",300);
}

int valid_learn(object me)
{
    	object ob;
    	
    	if( me->query_skill("qiankunwuxing",1) >= me->query_skill("celecurse", 1))
    	   	return notify_fail("ѧϰǬ��������Ҫ��ͬ�ȼ���ͨ�콵��������\n");
		
		return ::valid_learn(me);
}


int help(object me)
{
	write(@HELP   
Ǭ�����οɴ����촸��ѧ�ã����ߴ���ɲ����ѧһЩ���š�

�������ù���г�������ֻ�������������Ż�������ˡ�
��Щ���������ս������ʹ�ã��µ�ָ�����ԭָ�
�����ؼ�����Ҫ��ͬ�ȼ���ͨ�콵Ϊ������
	
L0	��Ǭ��������boost�����鹥�����˵���Ѫ
		
L100	��Ǭ��������boom��
��������ָ�����50%��Ѫ��ÿ30����ʹ��һ��

L140	��Ǭ��ת����turn��
���鶨ʱ�������˵ľ�����

L150	��Ǭ��������heal��
�����ܹ���ս���ж�ʱҽ�����˵���Ѫ

L180	��Ǭ��������busy��
���鶨ʱ��ͼʹ����æ��

L185	��Ǭ����II����boom��
��������ָ�����75%��Ѫ��ÿ30����ʹ��һ��

L200	����Ǭ�����ε��ؼ�ת��ʹ��ʱ������æ�ң�ԭ��Ϊ����æ��1�֣�
HELP
    );
    return 1;
}
