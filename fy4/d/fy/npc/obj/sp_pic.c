#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("������ͼ", ({ "haitu"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("no_split",1);
				set("desc_ext2","�U��������(1:100000000) �����������������������������������U
�U���������������������������������������������������������U
�U������������������������������������"HIR"��"NOR CYN"�������������������U\n");

                set("long", CYN"
                                         ~
        
             ~

                               ~   ~
                           
 
                   ��     ��          ��
          ��  ��   

               ��              ��      

   ��     ��           ��       ��             ��
        \n"NOR	);
                set("value", 1000);
				set("desc_ext","����(???)");
        }
        ::init_item();
}


