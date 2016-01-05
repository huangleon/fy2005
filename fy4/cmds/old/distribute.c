// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int gift_points;
	int used_gift_points;
	if( !arg ) return notify_fail("��Ҫ���䵽�ĸ������ϣ�\n");
	gift_points = me->query("gift_points");
	used_gift_points = me->query("used_gift_points");
	if( used_gift_points >= gift_points )
	return notify_fail("��û�в����㡣\n");
	if(me->is_busy())
	return notify_fail("���ϸ�������û��ɡ�\n");
	switch (arg) {
	case "����" :
	case "caizhi" :
			if((int) me->query("int") >=20)
			return notify_fail("��Ĳ����Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
			me->add("used_gift_points",1);
			me->add("int",1);
			break;
        case "����" :
        case "tizhi" :
                        if((int) me->query("con") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        break;
        case "����" :
        case "lingxing" :
                        if((int) me->query("spi") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("spi",1);
                        break;
        case "����" :
        case "meili" :
                        if((int) me->query("per") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("per",1);
                        break;
        case "����" :
        case "yongqi" :
                        if((int) me->query("cor") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("cor",1);
                        break;
        case "����" :
        case "liliang" :
                        if((int) me->query("str") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        break;
        case "����" :
        case "naili" :
                        if((int) me->query("dur") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("dur",1);
                        break;
        case "����" :
        case "renxing" :
                        if((int) me->query("fle") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("fle",1);
                        break;
        case "�ٶ�" :
        case "sudu" :
                        if((int) me->query("agi") >=20)
                        return notify_fail("����ٶ��Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        break;
        case "����" :
        case "qiliang" :
                        if((int) me->query("tol") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("tol",1);
                        break;
        case "����" :
        case "yunqi" :
                        if((int) me->query("kar") >=20)
                        return notify_fail("��������Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        break;
        case "����" :
        case "dingli" :
                        if((int) me->query("cps") >=20)
                        return notify_fail("��Ķ����Ѵﵽ�����ޣ��������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("cps",1);
                        break;
        default :
			return notify_fail("û�����������\n");

	}
	write("Ok.\n");
	me->start_busy(1);
	return 1;
}


int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	distribute <���Ե�>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ��������㽫���Ե���䵽��ָ���Ĳ����ϡ����Ե�
һ�������������Զ���ɸ��ġ�

distribute ���� ���㽫һ�����Է��䵽�����ϡ�

�粻���������ģ�����ƴ�����档
���� caizhi	���� tizhi
���� lingxing	���� meili
���� yongqi	���� liliang
���� naili	���� renxing
�ٶ� sudu	���� qiliang
���� yunqi	���� dingli

�йز����㣬���ԣ����ǣ������ȣ����μ� Help attributes.txt

[0;1;37m����������������������������������������������������������������[0m   
HELP
        );
        return 1;
}
