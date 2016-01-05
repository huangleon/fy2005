//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, string arg)
{
	int iron, i,duration;
	string msg;
	string *word;
	string *temp = ({"an", "ba", "hong", "ma", "mi", "ni" });
	
	if (me->query("class")!= "lama")
		return notify_fail("ֻ�д��ѵ��Ӳ��������������ԡ�\n");
		
	iron = me->query_skill("kwan-yin-spells",1);
	if (iron < 200)
		return notify_fail("���������ԡ���Ҫ200�������������䡣\n");

	if (!arg)
		return notify_fail("������׼������������Ϊ��"+ me->query("marks/pfm/3word")+"\n");
	
/*	if (me->is_busy())
		return notify_fail("��������æ���޷���˼���ԡ�\n");
				
	if(me->is_fighting() )
		return notify_fail("���������ԡ�������ս���м��䡣\n");
*/
	
	word = allocate(3);
	
	if (sscanf(arg,"%s+%s+%s",word[0],word[1],word[2])!=3)
		return notify_fail("�����������õĸ�ʽ���ԣ���ο�help 3word\n");
	
	message_vision(HIY"$N"NOR+HIY"�����ڵأ�˫����£����ʮ������������ˣ������Ǿ�����������������η����֪������Ϊϣ�С�
���Թʣ�����˵����һ�����ۣ��ǵ�һ�����ۣ�������һ�����ۡ�\n"NOR,me);
	
	for (i=0;i<3;i++){
		if (member_array(word[i],temp)==-1)
			return notify_fail(word[i]+"������������֮һ��\n");
		write(" ��" + chinese_number(i+1) +"�������ǣ�" + word[i] +"\n");	
	}
	
	
	me->set("marks/pfm/3word",arg);
	
	return 1;
}



int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	3word[0m
[0;1;37m����������������������������������������������������������������[0m   

���Ѹ�ɮ�����������䵽200�����Ϻ󣬿�ͬʱ�̳��������ԣ�
���ǣ���ʹ��֮ǰ���뾲˼Ƭ�̼��䡣

��ʽ��������3word an+an+an
���磺	   3word an+ni+ni

ʹ��cast 3word ��ɽ�����ס������ͬʱ�̳���

��������������˵���ķѵķ�����಻����450����ɵ�����æ��
��಻����6��

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}