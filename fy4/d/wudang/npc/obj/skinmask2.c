inherit EQUIP;
void create()
{
        set_name("���", ({ "mask" }) );
        set_weight(600);
        set("long","һ�����µ���ߣ���Ȼ������ȥ���䵱�����ŵ���ò��\n");
                set("unit", "��");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
		set("fakegender", "����");
                set("armor_prop/id", ({"wudang master"}) );
                set("armor_prop/name", ({"�䵱������"}) );
		set("armor_prop/short", ({"�䵱������(wudang master)"}) );
                set("armor_prop/long", ({"һ����ɫ�԰׵����ˣ�üĿ��ȴ��⾼����\n"}) );
                set("wudang_skinmask",1);
}
