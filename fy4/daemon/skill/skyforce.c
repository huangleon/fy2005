// skyforce

#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","�̿��ķ�");
	set("type","force");
	set("effective_level",120);
	set("difficulty",200);
	set("usage/force",1);
	set("no_refund",({"henglian"}));
	set("skill_class","fugui");
	
}	

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	
	if (damage <=0)	return 0;	
	if( (me->query_temp("pfm/fg_erchuan")<=0 && me->query_temp("pfm/fg_sanchuan")<=0)
		|| me->query("class")!= "fugui"
		|| me->query_skill_mapped("iron-cloth")!= "henglian")
		return 0;
	
	if (me->query_temp("pfm/fg_erchuan")){
		me->add_temp("pfm/fg_erchuan",-1);
		data["msg"] = BBLU + WHT"$n�Ķ���������ȥ��$N�Ĺ�����\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/fg_erchuan") <= 0) {
			ANNIE_D->debuff(me,"stoneskin");
		}	
	} 
	/*
	else
	{
		me->add_temp("pfm/fg_sanchuan",-1);
		data["msg"] = BBLU + WHT"$n������ըɽ������ȥ��$N�Ĺ�����\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/fg_sanchuan") <= 0) {
			ANNIE_D->remove_buffup( me, me->query_temp("buff_type/ironup"));
		}
	}*/
	return data;	
}


int help(object me)
{
	write(@HELP   
���̿�ϴ����bikongxi��ҽ����Ѫ���� 
�������ա���danxinzhao��ҽ���������� 
����絴����qingfengdang)ҽ�ƾ������� 

������Ӣ�ۡ���hero��
ʹ�ô��ķ�����30���ڶ��ѿ�ģ������һ�ֵĹ����������
�߻�˷����꣩һ�Ρ�ÿ5����ʹ��һ�Ρ�
��160���ı̿��ķ���
ע�����ѱ���ʹ��һ��enable�˵��������ܣ�������������û
�����ơ�

���յ����롻��youdishenru��
ʹ�ô��ķ�����60����ģ��������Ѫ45%״̬��ÿ10����ʹ��һ�Ρ�
��160���ı̿��ķ���Ѫսǹ��190����

HELP
    );
    return 1;
}
