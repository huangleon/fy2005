// taoism.c

inherit SKILL;
void setup(){
	set("name","��ʦ����");
	set("skill_class","taoist");
	set("usage/literate",1);
	set("type","knowledge");
	set("effective_level",200);
	set("difficulty",250);
	set("no_refund",({"necromancy","scratmancy","gouyee"}));
}

int valid_learn(object me) 
{
        if(me->query("bellicosity") > 100 )
                return notify_fail("���ɱ��̫�أ��޷�������ʦ������\n");
        return 1;
}


int help(object me)
{
	write(@HELP   
��ʦ�����������书�Ļ�����200�����ϣ�ÿ2���г������ֹ��������
����+1%�ֿ���Ѫ�˺���������ֱ��220����+10%��

HELP
    );
    return 1;
}
