//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, string arg)
{
	int iron, i,duration;
	string msg;
	string *word;
	string *temp = ({"an", "ba", "hong", "ma", "mi", "ni" });
	string *ctemp = ({"������","���ȡ�","���衻","���","���䡻","���ء�"});
	
	if (me->query("class")!= "lama")
		return notify_fail("ֻ�д��ѵ��Ӳ��������������ԡ�\n");
		
	iron = me->query_skill("kwan-yin-spells",1);
	if (iron < 170)
		return notify_fail("���������ԡ���Ҫ170�������������䡣\n");

	if (!arg)
		return notify_fail("������׼���Ķ�������Ϊ��"+ me->query("marks/pfm/2word")+"\n");
	
/*	if (me->is_busy())
		return notify_fail("��������æ���޷���˼���ԡ�\n");
			
	if(me->is_fighting() )
		return notify_fail("���������ԡ�������ս���м��䡣\n");
*/
	
	word = allocate(2);
	
	if (sscanf(arg,"%s+%s",word[0],word[1])!=2)
		return notify_fail("�����������õĸ�ʽ���ԣ���ο�help 2word\n");
	
	message_vision(HIY"$N"NOR+HIY"�����ڵأ�˫����£����ʮ�����һ����Ϊ�������λ���Ӱ  ��¶����硡Ӧ�����ǹ�\n"NOR,me);
	
	for (i=0;i<2;i++){
		if (member_array(word[i],temp)==-1)
			return notify_fail(word[i]+"���ǿɼ������������֮һ��\n");
		write(" ��" + chinese_number(i+1) +"�������ǣ�" + word[i] +"\n");	
	}
		
	me->set("marks/pfm/2word",arg);
	
	
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	2word[0m
[0;1;37m����������������������������������������������������������������[0m   

���Ѹ�ɮ�����������䵽170�����Ϻ󣬿�ͬʱ�̳��������ԣ�
���ǣ���ʹ��֮ǰ���뾲˼Ƭ�̼��䡣

��ʽ��������2word an+an
���磺	   2word an+ni

ʹ��cast 2word ��ɽ�����ס������ͬʱ�̳���

���ڶ���������˵���ķѵķ�����಻����350����ɵ�����æ��
��಻����4��

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}