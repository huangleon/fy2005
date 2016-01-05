// enhance.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int points, to_pay,to_pay_exp;
	int enhanced = 0, price = 1;
	int base_exp = 50000;
	int base_pot = 10000;
	string msg, addthis;

	if( !arg ) return notify_fail("��Ҫ�����һ�����ԣ�\n");
	
//	points = me->query("potential") - me->query("learned_points");
	points = me->query("enhance/pot_save");
	
//	if (me->query("enhance/num")>10)
//		return notify_fail("��������ԵĴ������ܳ���10�Ρ�\n");
	
	if( (int) me->query("combat_exp") < 4000000 )
		return notify_fail("��ľ���̫�ͣ������ܹ�����κ����ԡ�\n");
	
	if( points < 30000 )
		return notify_fail("�����(enhancesave)��Ǳ�ܲ�������κ����ԡ�\n");

	if(me->is_busy())
		return notify_fail("���ϸ�������û��ɡ�\n");

	switch (arg) {
	case "����" :
	case "caizhi" :
			enhanced =  me->query("enhance/int");
			msg = "����";
			addthis = "int";
			to_pay= 90000;
			to_pay_exp=400000;
			break;
        case "����" :
        case "liliang" :
                        enhanced =  me->query("enhance/str");
                        msg = "����";
                        to_pay= 90000;
			to_pay_exp=400000;
                        addthis = "str";
                        break;         
        case "����" :
        case "naili" :
                        enhanced =  me->query("enhance/dur");
                        msg = "����";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "dur";
                        break;
        case "����" :
        case "tizhi" :
                        enhanced =  me->query("enhance/con");
                        msg = "����";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "con";
                        break;
        case "����" :
        case "yongqi" :
                        enhanced =  me->query("enhance/cor");
                        msg = "����";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "cor";
                        break;
        case "����" :
        case "renxing" :
                        enhanced =  me->query("enhance/fle");
                        msg = "����"; 
                        to_pay= 80000;
			to_pay_exp=200000;
                        addthis = "fle";
                        break;
        case "����" :
        case "yunqi" :
                        enhanced =  me->query("enhance/kar");
                        msg =  "����";
                        to_pay= 80000;
			to_pay_exp=200000;
                        addthis = "kar";
                        break;
        case "����" :
        case "lingxing" :
                        enhanced =  me->query("enhance/spi");
                        msg = "����";    
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "spi";
                        break;
        case "����" :
        case "meili" :
                        enhanced =  me->query("enhance/per");
                        msg = "����";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "per";
                        break;
        case "�ٶ�" :
        case "sudu" :                 
                        enhanced =  me->query("enhance/agi");
                        msg = "�ٶ�";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "agi";
                        break;
        case "����" :
        case "qiliang" :                    
                        enhanced =  me->query("enhance/tol");
                        msg =  "����";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "tol";
                        break;
        case "����" :
        case "dingli" :
                        enhanced =  me->query("enhance/cps");
                        msg = "����";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "cps";
                        break;
        default :
			return notify_fail("û�����������\n");

	}

	if (enhanced>4)
		return notify_fail("���Ѿ����ܼ������"+msg+"�ˡ�\n");
	
	enhanced=enhanced? enhanced*2:1;
	
	if (points < to_pay*enhanced) 
		return notify_fail("�����(enhancesave)��Ǳ�ܲ������"+msg+"��\n");
		
	me->add("enhance/" + addthis, 1);
	me->add(addthis, 1);
	me->add("enhance/pot_save",-to_pay*enhanced);
	me->add("combat_exp", -to_pay_exp*enhanced);
	me->add("enhance/num",1);
	write("���" + msg + "����ˣ�\n");
	me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	enhance <��������>[0m
[0;1;37m����������������������������������������������������������������[0m           

ָ���ʽ : enhance <�������>
���ָ��������㽫�洢��Ǳ�ܣ�enhancesave���;������������
ָ���Ĳ�������Ҫ����ֵ����4M����ʹ�á�

��һ��ʹ�ã�

����/����
enhance ���� ���㽫90000Ǳ�ܺ�400000�����������һ��������

����/����/����
enhance ���� ���㽫80000Ǳ�ܺ�300000�����������һ��������

����/����
enhance ���� ���㽫80000Ǳ�ܺ�200000�����������һ��������

����/����/����/�ٶ�/����
enhance ���� ���㽫30000Ǳ�ܺ�100000�����������һ�����ԡ�

��N��ʹ�õĻ���Ϊ��һ�ε�2^��N-1������

ע�����
ѧ�����������ʹ��Enhance��������˵��������Force��180������
��36������enhance��������ߵ�40���Ժ�ʹѧ��200��force����Ҳ
��ֻ��40��ÿ���������ֻ�������Ρ�

�粻���������ģ�����ƴ�����档
���� caizhi	���� tizhi
���� lingxing	���� meili
���� yongqi	���� liliang
���� naili	���� renxing
�ٶ� sudu	���� qiliang
���� yunqi	���� dingli

[0;1;37m����������������������������������������������������������������[0m 

HELP
        );
        return 1;
}
