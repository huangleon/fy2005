inherit __DIR__"tutor";

void create()
{
        set_name("ʮ��ױ�", ({ "wall","�ı�"}));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "��ϸ��֮��,��ǰ��Ȼ���ֻþ���ֻ������ս�����һ�У��Ʊ�������\nս������ʿ�ĳ�ǹɭȻ���򣬺�ӧ���ڣ�ǹâ������\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "spear");
 		set("teaching_limit", 400);
 	}
 	
 }
