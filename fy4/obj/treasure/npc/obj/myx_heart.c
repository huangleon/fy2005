inherit ITEM;

void create()
{
        set_name("�����ĵ���", ({ "heart of mingyue" }) );
				set_weight(400);
				if( clonep() )
					set_default_object(__FILE__);
				else {
		            set("unit", "��");
                set("long", "�������ģ��κη������顣\n");
								set("rigidity", 300);
                set("value", 100);
								set("weapon_material",1);
								set("material_level",135);
								set("desc_ext","��������(135)");

			}
    	::init_item();
}
