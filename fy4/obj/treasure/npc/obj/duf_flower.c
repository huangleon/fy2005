inherit ITEM;

void create()
{
        set_name("ɽ�軨", ({ "flower" }) );
				set_weight(400);
				if( clonep() )
					set_default_object(__FILE__);
				else {
		            set("unit", "��");
                set("long", "�ɶ��칤���ǽ����ɢ��������Ĺ�ʡ�\n");
								set("rigidity", 300);
                set("value", 100);
								set("weapon_material",1);
								set("material_level",130);
								set("desc_ext","��������(130)");

			}
    	::init_item();
}
