// XXDER
inherit ITEM;
void create()
{
        string *names = ({
                "�����ӡ�", "�����", "��ī�ӡ�",
                "�����", "�����ӡ�"
        });

        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600);
        set("unit", "��");
        set("long", "���Ƕ����˳������鼮��\n");
        set("value", 100);
        set("skill", ([
                "name":         "literate", 
                "exp_required": 0,          
                "sen_cost":     5,          
                "difficulty":   30,         
                "max_skill":    74,
		"literate":	"literate",
		"liter_level":	60,
        ]) );
}
