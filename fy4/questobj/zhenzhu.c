#include <armor.h>
#include <ansi.h>

inherit HEAD;
void create()
{
    	set_name(CYN"�׺�������"NOR, ({ "moonheart"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("long", CYN"
һ�����۰��С�ģ����Բ���Ŀ�����飬������¹�����˸������ѣĿ��
��ʹ⻪���ܾ���ǰ����˵������������ܻ�����ֵ���ǵı�ʯ�����Ǿ��˺�
���㣬�����������Ի�ȡ�Ƹ�����һ����ŭ�˺�֮�����߶���������û�˴�
�ء��������������󡣳�ˮ�˺��Ҵ���������ܿ�����ֻ����һ������
���°���һ�е����顣���Ǵ��������ǵļ�����·��ڸ������ǣ�������
��Ӧ��׷��ʲô�����������˰���������������Ķ�����

"NOR+HIR"                      ��ϧ���ɣ�ֱ����Զ!  \n\n"NOR);
        	set("unit", "��");
        	set("value", 0);
        	set("armor_prop/personality", 2);
           	set("wear_msg", HIC"$N����ذ�һ��$n"HIC"���ڷ����У���ʱ�������䶼����������\n$N��ԡ����ʵĹ⻪�У��·������·�һ�㡣\n"NOR);
        	set("unequip_msg", HIC"$NС������ذ�$n"HIC"����������\n"NOR);
		set("female_only", 1);
        }
        ::init_head();
}

