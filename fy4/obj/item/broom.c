#include <weapon.h>

inherit STAFF;

void create()
{
    set_name("����ɨ��", ({"bamboo broom", "broom"}) );
    set_weight(1000);
    if( clonep() )
             set_default_object(__FILE__);
    else {
          set("unit", "��");
          set("long", "һ�ѿ�ͺ��ͷ����ɨ�ѡ�\n");
          set("value", 50);
          set("material", "bamboo");
          set("wield_msg", "$N����һ��$n�������С�\n");
          set("unwield_msg", "$N�������е�$n��\n");
         } 
   ::init_staff(6);

}
