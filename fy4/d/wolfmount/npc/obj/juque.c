// Tie@fengyun
#include <weapon.h>

inherit DAGGER;

void create()
{
    set_name("����", ({ "ancient dagger","dagger" }) );
        set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
	        set("long", "����ʱ������ʦŷұ�������������С��ѱ���֮һ��С�����磬�н����\n");
	        set("value", 500);
		set("material", "steel");
	        set("wield_msg", "����һ�����绮�Ƴ��գ�һ�Ѻ���������$n�Ѻ�Ȼ����$N���С�\n");
	        set("unwield_msg", "$NС���������е�$n����Ƥ�ʡ�\n");
	}
    	
    	::init_dagger(95);
}
