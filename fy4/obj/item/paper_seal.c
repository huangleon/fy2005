// paper_seal.c
inherit COMBINED_ITEM;

void create() {
	set_name("�ҷ�ֽ", ({"paper seal", "seal", "paper"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","���ǵ�ʿ�����������ķ�ֽ�����з�淨���Ĺ��á�\n");
		set("unit", "��");
        	set("base_unit", "��");
        	set("base_weight", 5);
		set("base_value", 20);
		set("fast_grab",1);
		set("volumn",50);
	}
	set_amount(50);
}
