// annie 6.27

inherit SKILL;

void setup(){
	set("name","��а�ľ�");
	set("type","force");
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","demon");
	set("effective_level",150);
}

int help(object me)
{
	write(@HELP   
��ϵ���ؼ�ʹ��perform force.xxxx ��ʽ	
ΪNPCר�ã�û�о�����������
	
��������ȱ����baocanshouque��
����ֵĻ���Ӳ����60����ʧȥЧ��

���޶����С���wudumiaodi��
�������ѧ���ܻ�������������˺���
�����˺�������=���ּ�������*���ּ�������*2
��Ч������120�����ʧ

����ɢ���塻��deathgrip��
�������60���ڶ���Ѫ�˺��ֿ��½�100%

����ʹ������lessdeathgrip��
�������60���ڶ���Ѫ�˺��ֿ��½�50%

��Ǭ����Ų�ơ���disorder��
�����еĶ����໥����һ��

���������𡻣�guishenpomie��
�����ڳ����е��˵��ٻ���

���������𡻣�check_gspm��
һ������ڳ��ٻ��޵ĺ���

��������롻(lobotomy)
���ź�����

����������(manaburst)
�����ֵ��鷨����תΪ�������˺�

������������(manaflare)
����������תΪ��Ѫ�˺�

��ǧ�������(mystbusy)
״̬��ÿ�η���ʱ��ǰæ��+1

���黪�ɼ�����replenish��
�������ϵİ�����Ŀ

����ħ���Ρ���terror��
��ͼ�����ڳ����е���

����ħ���Ρ���terror2��
��ͼ�����ڳ�N-1������

���ջ���Ѫ����curseflesh��
30�������лָ�ת��Ϊ�˺�

buffup �� resurrect ϵ�в���ʹ��

HELP
    );
    return 1;
}
