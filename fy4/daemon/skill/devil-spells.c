// devil-spells.c

inherit SKILL;
void setup(){
	set("name","��ڤħ��");
	set("usage/spells",1);
	set("type","spells");
	set("effective_level",150);
	set("difficulty",200);
	set("skill_class","demon");
	
		
}	


int help(object me)
{
	write(@HELP   
��ħ�����꡻��soul-flame��
ȼ����Χ���е��ˣ��������4�ξ������˺���
���ؼ��������ص㣺
1��ÿ���˺�����Ϊ��һ�ε�2/3
2�����еĵ�һ�������˺������һ������Ϊ1/2��
����һ��Ϊ1/3���������εݼ�

�Ĵ��˺�֮�ͣ�
�˾�= lvl/num*3/2 *65/27
����= (lvl/num*2 + 50)* 65/27
����= lvl/num*4/3 *65/27

Lvl = ��Ч�����ȼ�
num = �ڼ������յ���

HELP
    );
    return 1;
}
